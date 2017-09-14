#include "tcpclient.h"
#include <QHostAddress>
#include <QDataStream>
#include <QFileInfo>

ClientTcp::ClientTcp(QString hostAddress, qint16 port, QObject *parent)
    : QObject(parent)
{

    loadSize = 40*1024;
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;

    totalReceivelBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;

    this->hostAddress = hostAddress;
    this->port = port;

    tcpClient = new QTcpSocket(this);
    //当连接服务器成功时，发出connected()信号，我们开始传送文件
    connect(tcpClient,SIGNAL(connected()),this,SLOT(StartTransfer()));
    //当有数据发送成功时，我们更新进度条
    connect(tcpClient,SIGNAL(bytesWritten(qint64)),this,SLOT(UpdateClientProgress(qint64)));
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(DisplayError(QAbstractSocket::SocketError)));
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(slotReceiveFile()));
    //Add Ready Read
}


ClientTcp::~ClientTcp()
{

}

void ClientTcp::SendFile(QString fileName)
{
    this->fileName = fileName;

    //初始化已发送字节为0
    bytesWritten = 0;
    tcpClient->connectToHost(QHostAddress(hostAddress), port); //连接
}

void ClientTcp::ConnectLong()
{
    tcpClient->connectToHost(QHostAddress(hostAddress), port); //连接
}

void ClientTcp::Sendclose()
{
    if(tcpClient->isOpen())
    {
        tcpClient->close();
    }
}


void ClientTcp::StartTransfer()                          //发送文件大小等信息
{
    qDebug() << fileName;
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
       qDebug() << "open file error!";
       return;
    }
    //文件总大小
    totalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_5_6);
    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    QString cmd = "SENDFILE";
    sendOut << qint64(0) << qint64(0) << currentFileName << cmd;
    //依次写入总大小信息空间，文件名大小信息空间，文件名---仅是文件名不含路径，没必要含路径
    totalBytes += outBlock.size();
    qDebug() << totalBytes;
    qDebug() << outBlock.size();
    //这里的总大小是文件名大小等信息和实际文件大小的总和
    sendOut.device()->seek(0);
    sendOut<<totalBytes<<qint64((outBlock.size() - sizeof(qint64)*2 - cmd.size()));
    //totalBytes是文件总大小，即两个quint64的大小+文件名+文件实际内容的大小
    //qint64((outBlock.size() - sizeof(qint64)*2) - cmd.size())得到的是文件名大小
    bytesToWrite = totalBytes - tcpClient->write(outBlock);
    //发送完头数据后剩余数据的大小，即文件实际内容的大小
    outBlock.resize(0);
}

void ClientTcp::UpdateClientProgress(qint64 numBytes)             //发送数据，更新进度
{
    bytesWritten += (int)numBytes;
    //已经发送数据的大小
    if(bytesToWrite > 0) //如果已经发送了数据
    {
       outBlock = localFile->read(qMin(bytesToWrite,loadSize));
     //每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，
     //就发送剩余数据的大小
       bytesToWrite -= (int)tcpClient->write(outBlock);
       //qDebug() << bytesToWrite;
      //发送完一次数据后还剩余数据的大小
       outBlock.resize(0);
      //清空发送缓冲区
    }
    else
    {
       localFile->close(); //如果没有发送任何数据，则关闭文件
    }
    //emit ProgressNum(totalBytes,bytesWritten);
    if(bytesWritten == totalBytes) //发送完毕
    {
       localFile->close();
       tcpClient->close();
    }
}

void ClientTcp::DisplayError(QAbstractSocket::SocketError) //显示错误
{
    QString e = tcpClient->errorString();
    emit SendError(e);
    tcpClient->close();
}

void ClientTcp::slotReceiveFile()
{
    QDataStream in(tcpClient);
    in.setVersion(QDataStream::Qt_5_6);

    if(bytesReceived <= sizeof(qint64)*2)
    { //如果接收到的数据小于16个字节，那么是刚开始接收数据，我们保存到//来的头文件信息

        qDebug() << tcpClient->bytesAvailable() ;
        if((tcpClient->bytesAvailable() >= sizeof(qint64)*2)&& (fileNameSize == 0))
        { //接收数据总大小信息和文件名大小信息
            in >> totalReceivelBytes >> fileNameSize;
            bytesReceived += sizeof(qint64) * 2;
        }

        if((tcpClient->bytesAvailable() >= fileNameSize) && (fileNameSize != 0))
        {  //接收文件名和命令选项，并建立文件
            QString cmd;
            in >> receiveFileName >> cmd;
            qDebug() << "Receive" << receiveFileName;
            qDebug() << "Cmd" << cmd;
            receiveFileName.replace("\\","/");
            receiveFileName="./"+QFileInfo(receiveFileName).fileName();
            bytesReceived += fileNameSize;
            bytesReceived += cmd.size();
            localReceiveFile = new QFile(receiveFileName);
            if(!localReceiveFile->open(QFile::WriteOnly))
            {
                qDebug() << "open file error!";
                return;
            }
        }
        else   return;
    }

    if(bytesReceived < totalReceivelBytes)
    {  //如果接收的数据小于总数据，那么写入文件
        bytesReceived += tcpClient->bytesAvailable();
        inBlock = tcpClient->readAll();
        localReceiveFile->write(inBlock);
        inBlock.resize(0);
    }
    if(bytesReceived == totalReceivelBytes)
    {
//接收数据完成时
//        tcpServerConnection->close();
//        localFile->close();
    }
}



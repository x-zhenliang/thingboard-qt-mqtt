#include "tcpserver.h"


ServerTcp::ServerTcp(QString hostAddress, qint16 port, QObject *parent)
    : QObject(parent)
{
    loadSize = 4*1024;
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;

    totalReceiveBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    this->hostAddress = hostAddress;
    this->port = port;

    connect(&tcpServer,SIGNAL(newConnection()),this,SLOT(AcceptConnection()));
}

int ServerTcp::start()
{
    bytesReceived =0;
    if(!tcpServer.listen(QHostAddress(hostAddress),port))
    {
        qDebug() << tcpServer.errorString();
        return -1;
    }
    return 0;
}


void ServerTcp::AcceptConnection()
{
    clientConnection = new QTcpSocket;
    clientConnection = tcpServer.nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(UpdateServerProgress()));
    connect(clientConnection, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(DisplayError(QAbstractSocket::SocketError)));
    connect(clientConnection, SIGNAL(bytesWritten(qint64)), this, SLOT(UpdateClientProgress(qint64)));
    tcpServer.close();
}


void ServerTcp::UpdateServerProgress()
{
    QDataStream in(clientConnection);
    in.setVersion(QDataStream::Qt_5_6);

    if(bytesReceived <= sizeof(qint64)*2)
    { //如果接收到的数据小于16个字节，那么是刚开始接收数据，我们保存到//来的头文件信息

       if((clientConnection->bytesAvailable() >= sizeof(qint64)*2)&& (fileNameSize == 0))
       { //接收数据总大小信息和文件名大小信息
           in >> totalReceiveBytes >> fileNameSize;
           bytesReceived += sizeof(qint64) * 2;
       }

       if((clientConnection->bytesAvailable() >= fileNameSize)
               && (fileNameSize != 0))
       {  //接收文件名，并建立文件
           in >> fileReceiveName;
           fileReceiveName.replace("\\","/");
           fileReceiveName=fileSavePath+"/"+QFileInfo(fileReceiveName).fileName();
           qDebug()<<fileReceiveName;
           bytesReceived += fileNameSize;
           localReceiveFile = new QFile(fileReceiveName);
           if(!localReceiveFile->open(QFile::WriteOnly))
           {
               qDebug() << "open file error!";
               return;
           }
       }
       else return;
    }


    if(bytesReceived < totalReceiveBytes)
    {  //如果接收的数据小于总数据，那么写入文件
       bytesReceived += clientConnection->bytesAvailable();
       inBlock = clientConnection->readAll();
       localReceiveFile->write(inBlock);
       inBlock.resize(0);
    }
    if(bytesReceived == totalReceiveBytes)
    { //接收数据完成时
//       tcpServerConnection->close();
//       localFile->close();
    }
}

void ServerTcp::DisplayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << clientConnection->errorString();
    clientConnection->close();
}

void ServerTcp::UpdateClientProgress(qint64 numBytes)
{
    bytesWritten += (int)numBytes;
    //已经发送数据的大小
    if(bytesToWrite > 0) //如果已经发送了数据
    {
       outBlock = localFile->read(qMin(bytesToWrite,loadSize));
       //每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，
       //就发送剩余数据的大小
       bytesToWrite -= (int)clientConnection->write(outBlock);
       qDebug() << bytesToWrite;
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
         // tcpClient->close();
    }
}

void ServerTcp::SendFileHeader(QString fileName)
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
    sendOut << qint64(0) << qint64(0) << currentFileName;
    //依次写入总大小信息空间，文件名大小信息空间，文件名---仅是文件名不含路径，没必要含路径
    totalBytes += outBlock.size();
    //这里的总大小是文件名大小等信息和实际文件大小的总和
    sendOut.device()->seek(0);
    sendOut<<totalBytes<<qint64((outBlock.size() - sizeof(qint64)*2));
    //totalBytes是文件总大小，即两个quint64的大小+文件名+文件实际内容的大小
    //qint64((outBlock.size() - sizeof(qint64)*2))得到的是文件名大小
    bytesToWrite = totalBytes - clientConnection->write(outBlock);
    //发送完头数据后剩余数据的大小，即文件实际内容的大小
    outBlock.resize(0);
}

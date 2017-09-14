#include "udptrans.h"
#include <QDataStream>
#include <QTimer>
#include <QFileInfo>

#define CMD_GET "GETFILE"
#define CMD_SEND "SENDFILE"

ClientUdp::ClientUdp(QString hostAddress, qint16 port, QObject *parent )
         : QObject(parent)
{
    this->hostAddress = hostAddress;
    this->port = port;

    totalSendBytes = 0;
    count = 0;
    sendFlag = false;
    bytesWritten = 0;

    totalReceivelBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;


    clientUdp = new QUdpSocket(this);
    clientUdp->bind(this->port, QUdpSocket::ShareAddress);//监控端口
    connect(clientUdp, SIGNAL(readyRead()), this, SLOT(slotReadData()));
}

ClientUdp::~ClientUdp()
{
}

void ClientUdp::SendFile(QString fileName,QString cmd)
{
    //先发送文件名称
    localSendFile = new QFile(fileName);
    if(!localSendFile->open(QFile::ReadOnly))
    {
      qDebug() << "open file error!";
      return;
    }
    totalSendBytes = localSendFile->size();
    qDebug() << "FileSize:" << localSendFile->size();

    QDataStream sendOut(&sendBlock, QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_5_6);
    QString currentFileName = fileName.right(fileName.size()-fileName.lastIndexOf('/')-1);
    sendOut<<qint64(0)<<qint64(0)<<currentFileName << cmd;
    totalSendBytes += sendBlock.size();
    sendOut.device()->seek(0);
    sendOut << totalSendBytes << qint64(sendBlock.size() - sizeof(qint64)*2 - cmd.size());
    clientUdp->writeDatagram(sendBlock, sendBlock.size(), QHostAddress(hostAddress), port);
    sendBlock.resize(0);

    sendBlock = localSendFile->readAll();
    sendCount = (sendBlock.size() / (10* 1024)) + 1;

    if(cmd.contains("GET"))
    {
        return;
    }
    sendTimer = new QTimer(this);
    connect(sendTimer, SIGNAL(timeout()), this, SLOT(slotsendFileData()));//发送文件
    sendTimer->start(2);
}


void ClientUdp::slotReadData()
{
    if(clientUdp->hasPendingDatagrams())
    {
        QHostAddress *mhost= new QHostAddress();
        quint16      *mport= new quint16();
        if(bytesReceived <= sizeof(qint64)*2)
        {
            QDataStream  receiveIn(&receiveBlock, QIODevice::ReadOnly);
            receiveIn.setVersion(QDataStream::Qt_5_6);
            qint64 availableBytes = clientUdp->bytesAvailable();
            receiveBlock.resize(clientUdp->pendingDatagramSize());
            clientUdp->readDatagram(receiveBlock.data(), receiveBlock.size(), mhost, mport);

            if((availableBytes >= sizeof(qint64)*2)&& (fileNameSize == 0))
            {
               receiveIn >> totalReceivelBytes >> fileNameSize;
               bytesReceived += sizeof(qint64) * 2;
            }
            if((availableBytes >= fileNameSize) && (fileNameSize != 0))
            {  //接收文件名，并建立文件
                QString cmd;
                receiveIn >> receiveFileName >> cmd;
                receiveFileName.replace("\\","/");
                receiveFileName = fileSavePath + QFileInfo(receiveFileName).fileName();
                bytesReceived += fileNameSize;
                bytesReceived += cmd.size();
                localReceiveFile = new QFile(receiveFileName);
                if(!localReceiveFile->open(QFile::WriteOnly))
                {
                    qDebug() << "open file error!";
                    return;
                }
            }
            else
            {
                return;
            }
        }
        if(bytesReceived < totalReceivelBytes)
        {
            //如果接收的数据小于总数据，那么写入文件
            bytesReceived += clientUdp->bytesAvailable();
            receiveBlock.resize(clientUdp->pendingDatagramSize());
            clientUdp->readDatagram(receiveBlock.data(), receiveBlock.size(), mhost, mport);
            localReceiveFile->write(receiveBlock);
            receiveBlock.resize(0);
        }
        if(bytesReceived == totalReceivelBytes)
        {
            qDebug() << bytesReceived;
            //接收数据完成时
            // tcpClient->close();
            // localReceiveFile->close();
        }
     }
}


void ClientUdp::slotsendFileData()
{
    //qDebug() << sendFlag;
    if(!sendFlag)//如果没有完成发送
    {
        QByteArray dagram;
        dagram = sendBlock.mid((count*40*1024), 40*1024); //每包以40 * 1024字节发送
        clientUdp->writeDatagram(dagram, dagram.size(), QHostAddress(hostAddress), port);
        count++;
        bytesWritten += dagram.size();
        if(count == sendCount)//如果发送包数与应发包数相同，结束
            sendFlag = true;
    }
    else
    {
        qDebug() << bytesWritten;
        //完成发送
        sendBlock.resize(0);
        sendTimer->stop();
        bytesWritten = 0;
        count = 0;
        sendFlag = false;
    }
}











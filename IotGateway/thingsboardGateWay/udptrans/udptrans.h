#ifndef UDPTRANS_H
#define UDPTRANS_H

#include <QObject>
#include <QUdpSocket>
#include <QFile>
class QTimer;

class ClientUdp : public QObject
{
    Q_OBJECT

public:
    ClientUdp(QString hostAddress, qint16 port, QObject *parent = 0);
    ~ClientUdp();
    void SendFile(QString fileName, QString cmd);

private:
    QUdpSocket *clientUdp;
    QFile  *localSendFile;      //待发送的文件指针
    QString sendFileName;       //待发送的文件路径
    qint64  totalSendBytes;     //待发送数据的大小
    qint64  bytesWritten;       //已经发送数据大小
    qint64  bytesToWrite;       //剩余要发送数据大小
    qint64  loadSendSize;       //每次发送数据的大小
    QByteArray sendBlock;       //数据缓冲区，即存放每次要发送的数据
    qint64     sendCount;
    bool    sendFlag;
    qint16  count;

    QString     fileSavePath;
    qint64      totalReceivelBytes;  //存放总大小信息
    qint64      bytesReceived;       //已收到数据的大小
    qint64      fileNameSize;        //文件名的大小信息
    QString     receiveFileName;     //存放文件名
    QFile      *localReceiveFile;    //本地文件
    QByteArray  receiveBlock;        //接受数据缓冲区

    QString     fileName;
    QString     hostAddress;
    qint16      port;
    QTimer      *sendTimer;

public slots:
    void slotReadData();
    void slotsendFileData();
};
#endif




//loadSendSize = 4*1024;
//totalSendBytes = 0;
//bytesWritten = 0;
//bytesToWrite = 0;

//totalReceivelBytes = 0;
//bytesReceived = 0;
//fileNameSize = 0;

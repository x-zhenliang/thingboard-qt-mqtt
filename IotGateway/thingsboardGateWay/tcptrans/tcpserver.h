#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QFileInfo>
#include <QFile>
#include <QDataStream>

class ServerTcp : public QObject
{
    Q_OBJECT
public:
    ServerTcp(QString hostAddress, qint16 port, QObject *parent = 0);
    int start();   //开始监听
    QString hostAddress;
    QString fileSavePath;
    qint16  port;

private slots:
    void AcceptConnection();  //建立连接
    void UpdateServerProgress();  //更新进度条，接收数据
    void DisplayError(QAbstractSocket::SocketError socketError);
    void UpdateClientProgress(qint64 numBytes);
    void SendFileHeader(QString fileName);

private:
    QTcpServer tcpServer;
    QTcpSocket *clientConnection;
    qint64     totalReceiveBytes;    //存放总大小信息
    qint64     bytesReceived;        //已收到数据的大小
    qint64     fileNameSize;         //文件名的大小信息
    QString    fileReceiveName;      //存放文件名
    QFile      *localReceiveFile;    //本地文件
    QByteArray inBlock;              //数据缓冲

    QFile *localFile;      //要发送的文件
    qint64 totalBytes;     //数据总大小
    qint64 bytesWritten;   //已经发送数据大小
    qint64 bytesToWrite;   //剩余数据大小
    qint64 loadSize;       //每次发送数据的大小
    QByteArray outBlock;   //数据缓冲区，即存放每次要发送的数据
    QString fileSendName;  //Send File Name
};

#endif

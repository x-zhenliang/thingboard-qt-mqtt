#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QFile>
#include <QTcpSocket>


class ClientTcp : public QObject
{
    Q_OBJECT

public:
    explicit ClientTcp(QString hostAddress, qint16 port, QObject *parent = 0);
    ~ClientTcp();
    void SendFile(QString fileName);
    void Sendclose();
    void ConnectLong();


private:
        QTcpSocket *tcpClient;
        QFile *localFile;      //要发送的文件
        qint64 totalBytes;     //数据总大小
        qint64 bytesWritten;   //已经发送数据大小
        qint64 bytesToWrite;   //剩余数据大小
        qint64 loadSize;       //每次发送数据的大小
        QByteArray outBlock;   //数据缓冲区，即存放每次要发送的数据
        QString hostAddress;
        qint16 port;

        QString fileSavePath;
        qint64 totalReceivelBytes;  //存放总大小信息
        qint64 bytesReceived;  //已收到数据的大小
        qint64 fileNameSize;  //文件名的大小信息
        QString receiveFileName;   //存放文件名
        QFile *localReceiveFile;   //本地文件
        QByteArray inBlock;   //数据缓冲
        QString fileName;

private slots:
    void StartTransfer();                            //发送文件大小等信息
    void UpdateClientProgress(qint64);               //发送数据，更新进度
    void DisplayError(QAbstractSocket::SocketError); //显示错误
    void slotReceiveFile();

signals:
    void ProgressNum(qint64 count, qint64 over);
    void SendError(QString error);
};

#endif

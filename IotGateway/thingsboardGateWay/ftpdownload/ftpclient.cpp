#include "ftpclient.h"

FtpClient::FtpClient()
{

    //    client.FtpSetUserInfor("userFtpName", "userFtpPwd");
    //    client.FtpSetHostPort("userHost");
    //    client.FtpPut("F:\\this_qt\\ftp\\image\\4.jpg", "3.jpg");
    //    client.FtpGet("1.jpg", "F:\\this_qt\\ftp\\image\\2.jpg");

    namManager = new QNetworkAccessManager();
    uUrl = new QUrl();
    uUrl->setScheme("ftp");
    connect(namManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slotFinished(QNetworkReply *)));
}

FtpClient::~FtpClient()
{
}

void FtpClient::FtpGet(QString sor, QString dev)
{
    QFileInfo info;
    info.setFile(dev);
    fFile = new QFile(info.filePath());
    fFile->open(QIODevice::Append|QIODevice::WriteOnly);
    uUrl->setPath(sor);
    nrReply = namManager->get(QNetworkRequest(*uUrl));
}

void FtpClient::FtpPut(QString source, QString dev)
{
    QFile file(source);
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();


    uUrl->setPath(dev);
    namManager->put(QNetworkRequest(*uUrl), data);
}

void FtpClient::FtpSetUserInfo(QString user, QString pwd)
{
    uUrl->setUserName(user);
    uUrl->setPassword(pwd);
}

void FtpClient::FtpSetHostPort(QString str, int port)
{
    uUrl->setHost(str);
    uUrl->setPort(port);
}

void FtpClient::slotFinished(QNetworkReply * reply)
{
    fFile->write(reply->readAll());
    fFile->flush();
    fFile->close();
    reply->deleteLater();
}




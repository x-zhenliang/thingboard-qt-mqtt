#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include <QObject>
#include <QFile>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QByteArray>
#include <QFileInfo>
#include <QDir>

class FtpClient : public QObject
{
    Q_OBJECT

public:
    explicit FtpClient();
    ~FtpClient();
    void FtpGet(QString sor, QString dev);
    void FtpPut(QString source, QString dev);
    void FtpSetUserInfo(QString user, QString pwd);
    void FtpSetHostPort(QString str, int port =21);
private:
    QFile * fFile;
    QNetworkReply *nrReply;
    QNetworkAccessManager * namManager;
    QUrl * uUrl;

protected slots:
    void slotFinished(QNetworkReply * reply);
};

#endif // FTPCLIENT_H



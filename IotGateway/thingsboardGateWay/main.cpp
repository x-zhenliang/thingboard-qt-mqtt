#include <QCoreApplication>
#include "nthingboard.h"
#include "ftpdownload/ftpclient.h"
#include "tcptrans/tcpclient.h"
#include "udptrans/udptrans.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    NThingBoard nthingGateway(argc, argv);
//    nthingGateway.exec();
    ClientTcp client("10.50.200.134",6666);
    client.SendFile("/home/xiaoxie/thingsboard/thingsboard-1.2.3.deb");
//    FtpClient client;
//    client.FtpSetHostPort("10.50.200.194");
//    client.FtpSetUserInfo("xiexie", "123456");
//    client.FtpGet("网关.txt", "./网关.txt");

//    ClientUdp udp("10.50.200.201",6666);
//    udp.SendFile("/home/xiaoxie/thingsboard/thingsboard-1.2.3.deb","SENDFILE");

    return a.exec();
}


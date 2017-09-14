#include "daemonapplication.h"

int main(int argc, char *argv[])
{
    DaemonApplication daemon(argc, argv);
    return daemon.exec();
}

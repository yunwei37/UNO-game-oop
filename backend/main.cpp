#include <QCoreApplication>
#include "aithread.h"
#include "netthread.h"
#include <qtcpsocket.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AIthread *at = new AIthread();
    netThread *nt = new netThread();
    at->start();
    nt->start();
    return a.exec();
}

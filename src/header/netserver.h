#ifndef NETSERVER_H
#define NETSERVER_H
#include <qthread.h>
#include <QtNetwork>
#include <qtcpsocket.h>

class netServer: public QObject
{
        Q_OBJECT
public:
    netServer();
private:
    QUdpSocket* receiver;
private slots:
    void readPendingDatagrams();
};

#endif // NETSERVER_H

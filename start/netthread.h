#ifndef NETTHREAD_H
#define NETTHREAD_H
#include <qthread.h>
#include <iostream>
#include <QtNetwork>
#include "playerthread.h"
#include "backend.h"
#include "message.h"

class netThread: public playerThread
{
        Q_OBJECT
public:
    netThread(int id, Backend* b);
public slots:
    void start(int id);
private:
    QUdpSocket* sender;
    int netID;              // 用来在网络传输中同步playerID
};

#endif // NETTHREAD_H

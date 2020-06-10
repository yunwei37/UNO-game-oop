#ifndef NETSERVER_H
#define NETSERVER_H
#include <qthread.h>
#include <qtcpsocket.h>

class netServer: public QThread
{
        Q_OBJECT
public:
    netServer();
protected:
    void run();
private:

};

#endif // NETSERVER_H

#ifndef NETTHREAD_H
#define NETTHREAD_H
#include <qthread.h>
#include <iostream>
#include "playerthread.h"

class netThread: public playerThread
{
        Q_OBJECT
public:
    netThread();
protected:
    void run();
};

#endif // NETTHREAD_H

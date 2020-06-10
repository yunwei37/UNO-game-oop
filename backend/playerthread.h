#ifndef PLAYERTHREAD_H
#define PLAYERTHREAD_H

#include<qthread.h>

class playerThread:public QThread
{
            Q_OBJECT
public:
    playerThread();
};

#endif // PLAYERTHREAD_H

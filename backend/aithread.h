#ifndef AITHREAD_H
#define AITHREAD_H
#include <qthread.h>
#include <iostream>
#include "playerthread.h"

class AIthread: public playerThread
{
        Q_OBJECT
private:
    static const QString names[];
public:
    AIthread(int id);
public slots:
    void start();
};

#endif // AITHREAD_H

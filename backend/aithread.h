#ifndef AITHREAD_H
#define AITHREAD_H
#include <qthread.h>
#include <iostream>
#include "playerthread.h"

class AIthread: public playerThread
{
        Q_OBJECT
public:
    AIthread();
protected:
    void run();
};

#endif // AITHREAD_H

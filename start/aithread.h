#ifndef AITHREAD_H
#define AITHREAD_H
#include <iostream>
#include <qvector.h>
#include "playerthread.h"
#include "backend.h"

class AIthread: public playerThread
{
        Q_OBJECT
private:
    static const QString names[];
public:
    AIthread(int id, Backend* b);
public slots:
    void start(int id);
signals:

};

#endif // AITHREAD_H

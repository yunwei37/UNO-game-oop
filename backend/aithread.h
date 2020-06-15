#ifndef AITHREAD_H
#define AITHREAD_H
#include <qthread.h>
#include <iostream>
#include <qvector.h>
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
    void receivePossibles(QString cardIds);
signals:

};

#endif // AITHREAD_H

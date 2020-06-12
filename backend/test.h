#pragma once

#include <QCoreApplication>
#include "aithread.h"
#include "netthread.h"
#include <qtcpsocket.h>

class Controller : public QObject
{
    Q_OBJECT
        QThread workerThread;
public:
    Controller() {
        netThread* worker = new netThread(0);
        worker->moveToThread(&workerThread);
        connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
        connect(this, &Controller::operate, worker, &netThread::start);
        connect(worker, &netThread::actionReady, this, &Controller::handleResults);
        workerThread.start();
        emit operate();
    }
    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    void handleResults(const QString& r) {
        std::cout << r.toStdString();
    }
signals:
    void operate();
};

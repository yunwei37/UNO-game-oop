#ifndef PLAYERTHREAD_H
#define PLAYERTHREAD_H

#include<qthread.h>

class playerThread:public QObject
{
            Q_OBJECT
public:
    explicit playerThread(QObject* parent = nullptr);
    playerThread(int id, QObject* parent = nullptr);
    playerThread(int id, QString name, QObject* parent = nullptr);
protected:
    QString playerName;
    int playerID;
    int type;
signals:
    void actionReady(const QString&);
public:
    QString getPlayerName() const;
    void setPlayerName(QString playerName);

    int getPlayerID() const;
    int getType() const;
};

#endif // PLAYERTHREAD_H

#ifndef PLAYERTHREAD_H
#define PLAYERTHREAD_H

#include <qthread.h>
#include "cards.h"

class Backend;

class playerThread:public QObject
{
            Q_OBJECT
public:
    explicit playerThread(Backend* back, QObject* parent = nullptr);
    playerThread(int id, Backend* b,QObject* parent = nullptr);
    playerThread(int id, Backend* b,QString name, QObject* parent = nullptr);

    QString getPlayerName() const;
    void setPlayerName(QString playerName);

    int getPlayerID() const;
    int getType() const;
protected:
    QString playerName;
    int playerID;
    int type;
    Backend* back;
signals:
    void chooseDraw();
    void choosePlay(int cardID, Card::COLOR color);
    void chooseUno();

};

#endif // PLAYERTHREAD_H

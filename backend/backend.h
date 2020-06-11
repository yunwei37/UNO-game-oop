#ifndef BACKEND_H
#define BACKEND_H

#include "aithread.h"
#include "netthread.h"
#include "cards.h"
#include <qvector.h>
#include <playerthread.h>

class backend{
private:
    QVector<playerThread> otherPlayers;
    
    QString myName;
    
    int playerCount;
    int netPlayerCount;
    int AIPlayerCount;
    
    int currentTimeSamp;
    
public:
    backend();
    backend(int playerNum,int netPlayerNum,int AIPlayerNum);
    
    // for the front to get current statue
    int getCurrentStatue();     // return statue id
    
    int getCurrnetTurnID();
    
    bool getMyCards(QVector<Card*> cards);

    bool getTopFiveCards(QVector<Card*> cards);
    
    int getPlayerCardCount(int playerID);
    QString getPlayerName(int playerID);

    Card* drawCard();

    void sayUNO();

    // set at the begining
    void setMyName(const QString &value);

    // call start
    void start();

signals:
    void AIMoveEnds();
    void netMoveEnds();
};


#endif // BACKEND_H

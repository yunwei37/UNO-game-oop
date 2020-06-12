#ifndef BACKEND_H
#define BACKEND_H

#include "aithread.h"
#include "netthread.h"
#include "cards.h"
#include <qvector.h>
#include <playerthread.h>


/*
    后端类：可以由前端进行获取状态信息和进行操作；
    每个其他玩家都是一个类，在backend中声明；

 */
class Backend{
private:
    QVector<playerThread*> Players;

    QVector<Card*> cards;

    
    int playerCount;
    int netPlayerCount;
    int AIPlayerCount;
    
    int currentTimeSamp;

public:
    Backend(int playerNum,int netPlayerNum,int AIPlayerNum, QString myName);
    ~Backend();

    // for the front to get current statue
    int getCurrentStatue();     // return statue id
    int getCurrnetTurnID();
    bool getMyCards(QVector<Card*>& cards);
    bool getTopFiveCards(QVector<Card*> &cards);
    int getPlayerCardCount(int playerID);
    QString getPlayerName(int playerID);


public slots:
    void start();
    void sayUNO();
    void playCard(int cardID);
    void reciveAction(const QString& action);

signals:
    void MoveEnds();
};


#endif // BACKEND_H

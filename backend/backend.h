#ifndef BACKEND_H
#define BACKEND_H

#include "aithread.h"
#include "netthread.h"
#include "cards.h"
#include <qvector.h>
#include <qlist.h>
#include <playerthread.h>


/*
    后端类：可以由前端进行获取状态信息和进行操作；
    每个其他玩家都是一个类，在backend中声明；前端和后端唯一的接口就是这个类。
    在前端每次完成相关显示动作之后调用函数

    getCurrentStatue();

    获取当前状态；注意，如果没有任何操作就能改变状态的话，该函数也会改变状态，如连续发牌，或跳过当前玩家；
    需要每次调用过getCurrentStatue()函数后依次查看其他信息是否有更改

    状态 flag：
        -2    Error
        -1      创建类时初始化，游戏准备状态，等待网络连接;
        0       进入游戏，开始发牌；
        1       当前玩家可进行操作，选择摸牌或出牌；
        2       当前玩家已选择摸牌，更新手牌；
        3       当前玩家在摸牌后可以选择出牌；（可能存在）
        4       当前玩家已选择出牌，更新手牌和牌堆；（如果出的是颜色牌，需要在前端选择颜色，这一部分交给前端判断）
        （2 - 4代表回合结束）
        对于下一个玩家，在其回合开始前可显示：
        5       上一个玩家忘了叫UNO，可以质疑；
        6       跳过回合
        7       需要摸牌n张并跳过回合
        8       游戏胜利
        9       游戏失败
 */

enum flags { Error = -2, Init = -1, Start, Opera, Draw, DrawPut, Put, ForgetUNO, Skip, DrawN, Win, Lost  };

class Backend:public QObject{
    Q_OBJECT
private:
    QVector<playerThread*> Players;
    QVector<QThread> workerThreads;
    QVector<Card*> cards;

    QList<Card*> queueTop;

    int playerCount;
    int netPlayerCount;
    int AIPlayerCount;

    flags currentStatue;
    int currentTurnId;
    int direction;

    bool unoflag;
    bool drawNflag;
    bool skipFlag;

    Card::COLOR currentColor;
    int nextDrawNum;

    // 辅助函数
    Card* randomCardFromStack();                    // 从牌堆里随机抓一张
    void getNextPlayer();                           // 改变currentTurnId
    void setAllFlagsFalse();                        // 置位所有的flag
    int getTopNum();

public:
    Backend(int playerNum, QString myName);         // single player
    Backend(int maxPlayerNum,int AInum, QString myName);       // net players
    ~Backend();

    // for the front to get current statue
    flags getCurrentStatue();     // return statue flag
    int getCurrnetTurnID();
    bool getMyCards(QVector<Card*>& cards);        // 返回我的手牌，供显示；
    bool getMyValidCards(QVector<int>& cardIDs);     // 返回我可以出牌的序号
    bool getTopFiveCards(QVector<Card*> &cards);        // 返回牌堆顶上的五张牌
    int getPlayerCardCount(int playerID);               
    QString getPlayerName(int playerID);            

    int countPoints(int playerID);                      // 结算的时候计算点数

public slots:
    // 前端调用
    void start();
    void sayUNO();
    void playCard(int cardID,Card::COLOR color);
    void drawCard();

    // 其他线程通信
    void reciveAction(const QString& action);

signals:
    void MoveEnds();
};

class StatueERROR {
public:
    StatueERROR() {
        this->errorMessage = "";
    }
    StatueERROR(QString errorMessage) {
        this->errorMessage = errorMessage;
        this->type = "statue";
   }
   QString errorMessage;
   QString type;
};

class StackNoCardError:public StatueERROR {
public:
    StackNoCardError() {
        this->type = "StackNoCardError";
        this->errorMessage = "StackNoCard";
    }
    StackNoCardError(QString errorMessage){
        this->type = "StackNoCardError";
        this->errorMessage = errorMessage;
    }
};

#endif // BACKEND_H

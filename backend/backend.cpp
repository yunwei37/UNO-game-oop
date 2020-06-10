#include "backend.h"

void backend::setMyName(const QString &value)
{
    myName = value;
}

backend::backend()
{
    for(Card aCard:allCards){
        aCard.setProcesser(0);
        aCard.setTimestamp(0);
    }
    this->currentTimeSamp = 0;
}

backend::backend(int playerNum, int netPlayerNum, int AIPlayerNum)
{
    backend();
    this->playerCount = playerNum;
    this->netPlayerCount = netPlayerNum;
    this->AIPlayerCount = AIPlayerNum;
}

int backend::getCurrentStatue()
{
    
}

bool backend::getMyCards(QVector<Card> &cards)
{
    
}

bool backend::getTopFiveCards(QVector<Card> &cards)
{

}

int backend::getPlayerCardCount(int playerID)
{
    
}

QString backend::getPlayerName(int playerID)
{

}

Card backend::drawCard()
{

}

void backend::sayUNO()
{

}

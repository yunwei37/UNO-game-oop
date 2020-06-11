#include "backend.h"

void backend::setMyName(const QString& value)
{
	myName = value;
}

backend::backend()
{

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
	return 0;
}

int backend::getCurrnetTurnID()
{
	return 0;
}

bool backend::getMyCards(QVector<Card*> cards)
{
	return true;
}

bool backend::getTopFiveCards(QVector<Card*> cards)
{
	return true;
}

int backend::getPlayerCardCount(int playerID)
{
	return 0;
}

QString backend::getPlayerName(int playerID)
{
	return "";
}

Card* backend::drawCard()
{
	return nullptr;
}

void backend::sayUNO()
{

}

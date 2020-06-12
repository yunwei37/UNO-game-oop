#include "backend.h"

void Backend::sayUNO()
{
}

void Backend::playCard(int cardID)
{
}

void Backend::reciveAction(const QString& action)
{

}

void Backend::start()
{

}

Backend::Backend(int playerNum, int netPlayerNum, int AIPlayerNum, QString myName)
{
	this->playerCount = playerNum;
	this->netPlayerCount = netPlayerNum;
	this->AIPlayerCount = AIPlayerNum;

	Card::getAllCards(cards);

	int i = 0;
	Players.append(new playerThread(0, myName, nullptr));

	for (int j = 0; j < netPlayerNum; ++j) {

	}
	for (int j = 0; j < AIPlayerNum; ++j) {

	}
}

Backend::~Backend()
{

}

int Backend::getCurrentStatue()
{
	return 0;
}

int Backend::getCurrnetTurnID()
{
	return 0;
}

bool Backend::getMyCards(QVector<Card*> &cards)
{
	return true;
}

bool Backend::getTopFiveCards(QVector<Card*> &cards)
{
	return true;
}

int Backend::getPlayerCardCount(int playerID)
{
	return 0;
}

QString Backend::getPlayerName(int playerID)
{
	return Players[playerID]->getPlayerName();
}


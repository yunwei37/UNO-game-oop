#include "netthread.h"
#include "backend.h"

netThread::netThread(int id, Backend* b) :playerThread(b)
{
	type = 1;
	playerID = id;
}

void netThread::start(int id) {
	if (id != playerID)
		return;
	int cardid;
	int colorid;
	QVector<int> validids;
	QVector<Card*> mycards;
	back->getPlayerCards(playerID, mycards);
	back->getPlayerValidCards(playerID, validids);
	if (validids.size() > 0) {
		cardid = validids[rand() % validids.size()];
		if (Card::getCardTypeById(cardid) == Card::WILD || Card::getCardTypeById(cardid) == Card::WILD_DRAW_FOUR)
			colorid = rand() % 4;
		if (mycards.size() == 2) {
			emit chooseUno();
		}
		emit choosePlay(cardid, (Card::COLOR)colorid);
	}
	else {
		emit chooseDraw();
	}
}

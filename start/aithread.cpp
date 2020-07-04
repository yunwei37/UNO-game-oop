#include "aithread.h"
#include <random>

AIthread::AIthread(int id,Backend* b):playerThread(b)
{
	type = 0;
	//playerName = names[rand() % 8];
	char buff[2] = "0";
	buff[0] += id;
	playerName = QString("AI No. ") + QString(buff);
	playerID = id;
}

void AIthread::start(int id) {
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

const QString AIthread::names[]  = { "AI No.1","AI No.2","AI No.3", "AI No.4","AI No.5","AI No.6","AI No.7", "AI No.8" };
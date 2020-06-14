#include "backend.h"

void Backend::sayUNO()
{
	unoflag = true;
}

void Backend::playCard(int cardID, Card::COLOR color)
{
	auto c = cards[cardID];
	c->setProcesser(100);
	if (queueTop.size() == 5) {
		queueTop.pop_front();
	}
	queueTop.push_back(c);
	auto type = c->getCardType();
	switch (type) {

	case Card::NUMBERIC:				 // 基础卡
		currentStatue = Put;
		setAllFlagsFalse();
		currentColor = c->getColor();
		break;

	case Card::WILD:
		this->currentColor = color;
		currentStatue = Put;
		setAllFlagsFalse();
		break;

	case Card::WILD_DRAW_FOUR:
		this->currentColor = color;
		currentStatue = Put;
		setAllFlagsFalse();
		drawNflag = true;
		nextDrawNum += 4;
		break;

	case Card::SKIP:
		currentStatue = Put;
		setAllFlagsFalse();
		skipFlag = true;
		currentColor = c->getColor();
		break;

	case Card::RESERVE:
		currentStatue = Put;
		setAllFlagsFalse();
		direction = -direction;
		currentColor = c->getColor();
		break;

	case Card::DRAW_TWO:
		currentStatue = Put;
		setAllFlagsFalse();
		drawNflag = true;
		nextDrawNum += 2;
		currentColor = c->getColor();
		break;

	}
	getNextPlayer();
}

void Backend::drawCard()
{
	currentStatue = Draw;
}

// net
void Backend::reciveAction(const QString& action)
{

}

void Backend::startGame()
{
	currentStatue = Start;
}

Card* Backend::randomCardFromStack()
{
	QVector<Card*> randv;
	for (auto c : cards) {
		if (c->getProcesser() == -1) {
			randv.append(c);
		}
	}
	if (randv.size() == 0) {
		throw StackNoCardError();
		return nullptr;
	}
	int index = rand() % (randv.size());
	return randv[index];
}

void Backend::getNextPlayer()
{
	if (direction == 1) {
		currentTurnId = (currentTurnId + 1) % playerCount;
	}
	else {
		currentTurnId = (currentTurnId - 1) >= 0 ? (currentTurnId - 1) : (playerCount - 1);
	}
}

void Backend::setAllFlagsFalse()
{
	skipFlag = false;
	unoflag = false;
	drawNflag = false;
}

int Backend::getTopNum()
{	
	if (queueTop.isEmpty())
		return -1;
	return queueTop.constLast()->getCardNum();
}

Backend::Backend(int playerNum, QString myName)
{
	this->playerCount = playerNum;
	this->AIPlayerCount = playerNum - 1;

	Card::getAllCards(cards);

	Players.push_back(new playerThread(0, myName, nullptr));

	for (int j = 0; j < this->AIPlayerCount; ++j) {
		Players.push_back(new AIthread(j + 1));
	}
	// move to thread
	for (int j = 0; j < this->AIPlayerCount; ++j) {
		//Players[j + 1]->moveToThread(&workerThreads[j]);
		//connect(&workerThreads[j], &QThread::finished, Players[j + 1], &QObject::deleteLater);
		connect(this, &Backend::StartMove, (AIthread*)Players[j + 1], &AIthread::start);
		//connect((AIthread*)&workerThreads[j], &AIthread::actionReady, this, &Backend::reciveAction);
		//workerThreads[j].start();
	}

	this->currentStatue = Init;
	this->currentTurnId = 0;
	setAllFlagsFalse();
	this->currentColor = Card::BLACK;
	this->nextDrawNum = 0;
	this->direction = 1;
}

Backend::Backend(int maxPlayerNum, int AInum, QString myName)
{
	this->AIPlayerCount = AInum;
	int i = 1;
	Players.push_back(new playerThread(0, myName, nullptr));
}

Backend::~Backend()
{
	for (auto p : Players) {
		delete p;
	}
	for (int i = 1; i < playerCount; ++i) {
		workerThreads[i - 1].quit();
		workerThreads[i - 1].wait();
	}
}

flags Backend::getCurrentStatue()
{
	flags save = currentStatue;
	Card* c;
	QVector<int> validids;
	QVector<Card*> mycards;
	switch (currentStatue)
	{
	case Error:						// 错误状态
		exit(1);
		break;
	case Init:						// 初始状态
		currentStatue = Init;
		// wait for net players to join
		break;
	case Start:							// 总共每人抽八张，抽牌过程由前端显示， 后端一次性完成
		currentStatue = Opera;
		for (auto p : Players) {		// 抽牌
			for (int i = 0; i < 8; ++i) {
				auto c = randomCardFromStack();
				c->setProcesser(p->getPlayerID());
			}
		}
		c = randomCardFromStack();								// 选一张牌作为基础牌开始
		c->setProcesser(100);
		queueTop.push_back(c);
		this->currentColor = c->getColor();
		if (this->currentColor == Card::BLACK) {				// 如果是黑色的，随机选一种颜色
			this->currentColor = (Card::COLOR)(rand() % 4);
		}
		direction = 1;
		break;
	case Opera:						// 玩家进行操作状态
		currentStatue = Opera;
		break;
	case Draw:						//  玩家抽牌后的状态
		getMyValidCards(validids);
		if (validids.isEmpty()) {
			currentStatue = Opera;
			getNextPlayer();
		}
		else {
			currentStatue = DrawPut;
		}
		break;
	case DrawPut:					// 玩家抽牌后等待出牌状态
		currentStatue = DrawPut;
		break;
	case Put:						// 玩家出牌后的状态
		getMyCards(mycards);
		if (skipFlag) {
			currentStatue = Skip;
		}
		else if (drawNflag) {
			currentStatue = DrawN;
		}
		else if (unoflag == false && mycards.size() == 1) {
			currentStatue = ForgetUNO;
		}
		else if (mycards.size() == 0) {
			if (currentTurnId == 0) {
				currentStatue = Win;
			}
			else {
				currentStatue = Lost;
			}
		}
		else {
			currentStatue = Opera;
		}
		getNextPlayer();
		break;
	case ForgetUNO:
		currentStatue = ForgetUNO;
		break;
	case Skip:
		currentStatue = Opera;
		setAllFlagsFalse();
		getNextPlayer();
		break;
	case DrawN:
		currentStatue = Opera;
		for (int i = 0; i < nextDrawNum; ++i) {
			c = randomCardFromStack();
			c->setProcesser(currentTurnId);
		}
		nextDrawNum = 0;
		setAllFlagsFalse();
		getNextPlayer();
		break;
	case Win:
		currentStatue = Win;
		break;
	case Lost:
		currentStatue = Lost;
		break;
	default:
		currentStatue = Error;
		throw StatueERROR();
		break;
	}
	return save;
}

int Backend::getCurrnetTurnID()
{
	return currentTurnId;
}

bool Backend::getMyCards(QVector<Card*>& mycards)
{
	for (auto c : cards) {
		if (c->getProcesser() == 0) {
			mycards.push_back(c);
		}
	}
	return true;
}

bool Backend::getMyValidCards(QVector<int>& cardIDs)
{
	QVector<Card*> mycards;
	getMyCards(mycards);
	int lastNum = getTopNum();
	for (auto c : mycards) {
		if (c->getCardNum() == lastNum || c->getColor() == currentColor || c->getColor() == Card::BLACK) {
			cardIDs.push_back(c->getCardId());
		}
	}
	return true;
}

bool Backend::getTopFiveCards(QVector<Card*>& tcards)
{	
	if (queueTop.isEmpty())
		return false;
	for (auto c : queueTop) {
		tcards.push_back(c);
	}
	return true;
}

int Backend::getPlayerCardCount(int playerID)
{
	int count = 0;
	for (auto c : cards) {
		if (c->getProcesser() == playerID) {
			count++;
		}
	}
	return count;
}

QString Backend::getPlayerName(int playerID)
{
	return Players[playerID]->getPlayerName();
}

int Backend::countPoints(int playerID)
{
	if (currentStatue != Lost) {
		return -1;
	}
	int count = 0;
	for (auto c : cards) {
		switch (c->getCardType()) {
		case Card::NUMBERIC:
			count += c->getCardNum();
		case Card::WILD:
		case Card::WILD_DRAW_FOUR:
			count += 40;
			break;
		case Card::RESERVE:
		case Card::SKIP:
		case Card::DRAW_TWO:
			count += 20;
			break;
		}
	}
	return count;
}


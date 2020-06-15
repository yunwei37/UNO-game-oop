#pragma once

#include <QCoreApplication>
#include "aithread.h"
#include "netthread.h"
#include <qtcpsocket.h>
#include<backend.h>

class Controller : public QObject
{
	Q_OBJECT;
public:
	int statue;
	int timestamp = 0;
	int playerCount;
	Controller(int i) {
		playerCount = i;
	}
	~Controller() {

	}
	void test() {
		auto b = createBack();
		connect(this, &Controller::operate, b, &Backend::startGame);
		connect(this, &Controller::draw, b, &Backend::drawCard);
		connect(this, &Controller::play, b, &Backend::playCard);
		connect(this, &Controller::uno, b, &Backend::sayUNO);
		for (int i = 0; i < playerCount; ++i) {
			std::cout << b->getPlayerName(i).toStdString() << std::endl;
		}
		printData(b);
		emit operate();
		printData(b);
		printData(b);
		while (true) {
			int cardid;
			int colorid;
			QVector<int> validids;
			QVector<Card*> mycards;
			b->getPlayerCards(b->getCurrnetTurnID(), mycards);
			b->getPlayerValidCards(b->getCurrnetTurnID(),validids);
			if (statue == 1 || statue == 3) {			// if opera
				if (validids.size() > 0) {
					std::cin >> cardid;
					if (Card::getCardTypeById(cardid) == Card::WILD || Card::getCardTypeById(cardid) == Card::WILD_DRAW_FOUR)
						std::cin >> colorid;
					if (cardid == -1) {
						chooseDraw();
					}
					else {
						while (validids.count(cardid) == 0) {
							std::cout << "Error!    ";
							std::cin >> cardid;
						}
						if (mycards.size() == 2) {
							chooseuno();
						}
						chooseplay(cardid, (Card::COLOR)colorid);
						printData(b);   // for put
					}
				}
				else {
					chooseDraw();
				}
			}
			printData(b);			// get next statue
			if (statue == 5) {
				printData(b);
			}
			if (statue == 8 || statue == 9) {
				for (int i = 0; i < playerCount; ++i) {
					std::cout << b->countPoints(i) << " ";
				}
				break;
			}
		}
		destroyBack(b);
	}
	void printData(Backend* b) {
		std::string statues[] = { "Init", "Start", "Opera", "Draw", "DrawPut", "Put", "ForgetUNO", "Skip", "DrawN", "Win", "Lost" };
		std::cout << "------------------------------------------ time: "<< timestamp++ << std::endl;
		statue = b->getCurrentStatue();
		std::cout << "statue: " << statues[statue + 1] << std::endl;
		std::cout << "turn: " << b->getCurrnetTurnID() << std::endl;
		int id = b->getCurrnetTurnID();
		QVector<Card*> mycards;
		QVector<int> validids;
		b->getPlayerCards(id,mycards);
		std::cout << "my cards: ";
		for (auto c : mycards) {
			std::cout << c->getCardId() << " ";
		}
		std::cout << std::endl;

		std::cout << "valid cards: " << std::endl;
		b->getPlayerValidCards(id,validids);
		for (auto i : validids) {
			printCard(i);
		}
		std::cout << std::endl;

		std::cout << "player card count: ";
		for (int i = 0; i < playerCount; ++i) {
			std::cout << b->getPlayerCardCount(i) << " ";
		}
		std::cout << std::endl;

		mycards.clear();
		b->getTopFiveCards(mycards);
		std::cout << "top 5: " << std::endl;
		for (auto c : mycards) {
			printCard(c->getCardId());
		}
		std::cout << std::endl;

	}
	void printCard(int id) {
		std::string colors[] = { "RED", "YELLOW", "BLUE", "GREEN", "LACK" };
		std::string types[] = { "NUMBERIC", "WILD", "WILD_DRAW_FOUR", "SKIP", "RESERVE", "DRAW_TWO" };
		std::cout << "card:" << id << " " << colors[Card::getColorById(id)] << " num: " << Card::getCardNumById(id)
			<< " type: " << types[Card::getCardTypeById(id)] << std::endl;
	}
	Backend* createBack() {
		return new Backend(playerCount, "me");
	}
	void destroyBack(Backend* b) {
		delete b;
	}
	void chooseDraw() {
		emit draw();
	}
	void chooseplay(int cardID, Card::COLOR color) {
		emit play(cardID, color);
	}
	void chooseuno() {
		emit uno();
	}
public slots:
	void handleResults(const QString& r) {
		std::cout << r.toStdString();
	}
	void AIEnds() {
		std::cout << "AI finish" << std::endl;
	}
signals:
	void operate();
	void draw();
	void play(int cardID, Card::COLOR color);
	void uno();
};

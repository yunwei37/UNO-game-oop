#include <QCoreApplication>
#include <QApplication>
#include "aithread.h"
#include "netthread.h"
#include "backend.h"
#include <qtcpsocket.h>
#include "test.h"

std::string Controller::colors[] = { "RED", "YELLOW", "BLUE", "GREEN", "LACK" };
std::string Controller::types[] = { "NUMBERIC", "WILD", "WILD_DRAW_FOUR", "SKIP", "RESERVE", "DRAW_TWO" };

void testCard() {
	for (int i = 0; i < 108; ++i) {
		Card* c = Card::getCardById(i);
		assert(Card::getCardTypeById(i) == c->getCardType());
		assert(Card::getColorById(i) == c->getColor());
		std::cout << c->getCardType() << std::endl;
		std::cout << c->getCardNum() << std::endl;
		std::cout << c->getCardId() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
	}
}


int main(int argc, char *argv[])
{	

	QApplication a(argc, argv);
	Controller c(8);
	c.test();
	c.test();
	return a.exec();


	//testCard();
}

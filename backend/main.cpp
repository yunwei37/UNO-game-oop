#include <QCoreApplication>
#include <QApplication>
#include "aithread.h"
#include "netthread.h"
#include "backend.h"
#include <qtcpsocket.h>
#include "test.h"

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
	/*
	QApplication a(argc, argv);
    Backend b(4,"");
	Controller c;
	
	return a.exec();
	*/
	testCard();
}

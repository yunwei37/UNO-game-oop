//
// Created by ubuntu on 2020/6/9.
//

#ifndef UNO_CARDS_H
#define UNO_CARDS_H

#include <QVector>

class Card {

public:

	enum class COLOR { RED, YELLOW, BLUE, GREEN, BLACK };
	enum class CARD_TYPE { NUMBERIC, WILD, WILD_DRAW_FOUR, SKIP, RESERVE, DRAW_TWO };

	// get attrs
	COLOR getColor() const;
	CARD_TYPE getCardType() const;
	int getCardId() const;
	int getCardNum() const;

	// get cards
	static void getAllCards(QVector<Card*>& cards);
	static Card* getCardById(int);

	// compares
	bool operator==(const Card& rhs) const;
	bool operator!=(const Card& rhs) const;

	int getProcesser() const;
	void setProcesser(int value);
	int getTimestamp() const;
	void setTimestamp(int value);

protected:
	COLOR color;
	CARD_TYPE cardType;
	int cardId;
	int cardNum;

	static  Card allCards[];

private:
	Card(COLOR color, CARD_TYPE cardType, int cardNum = -1);

	static int count;
	int processer;      // represents the card owner
	int timestamp;      // represents the last used time
};

int Card::count = 0;


Card Card::allCards[] = {

	/*  0 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 0),
	/*  1 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 1),
	/*  2 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 1),
	/*  3 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 2),
	/*  4 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 2),
	/*  5 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 3),
	/*  6 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 3),
	/*  7 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 4),
	/*  8 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 4),
	/*  9 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 5),
	/* 10 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 5),
	/* 11 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 6),
	/* 12 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 6),
	/* 13 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 7),
	/* 14 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 7),
	/* 15 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 8),
	/* 16 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 8),
	/* 17 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 9),
	/* 18 */		Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 9),
	/* 19 */		Card(Card::COLOR::RED, Card::CARD_TYPE::SKIP),
	/* 20 */		Card(Card::COLOR::RED, Card::CARD_TYPE::SKIP),
	/* 21 */		Card(Card::COLOR::RED, Card::CARD_TYPE::DRAW_TWO),
	/* 22 */		Card(Card::COLOR::RED, Card::CARD_TYPE::DRAW_TWO),
	/* 23 */		Card(Card::COLOR::RED, Card::CARD_TYPE::RESERVE),
	/* 24 */		Card(Card::COLOR::RED, Card::CARD_TYPE::RESERVE),

	/* 25 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 0),
	/* 26 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 1),
	/* 27 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 1),
	/* 28 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 2),
	/* 29 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 2),
	/* 30 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 3),
	/* 31 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 3),
	/* 32 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 4),
	/* 33 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 4),
	/* 34 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 5),
	/* 35 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 5),
	/* 36 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 6),
	/* 37 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 6),
	/* 38 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 7),
	/* 39 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 7),
	/* 40 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 8),
	/* 41 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 8),
	/* 42 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 9),
	/* 43 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 9),
	/* 44 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::SKIP),
	/* 45 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::SKIP),
	/* 46 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::DRAW_TWO),
	/* 47 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::DRAW_TWO),
	/* 48 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::RESERVE),
	/* 49 */		Card(Card::COLOR::YELLOW, Card::CARD_TYPE::RESERVE),

	/* 50 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 0),
	/* 51 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 1),
	/* 52 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 1),
	/* 53 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 2),
	/* 54 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 2),
	/* 55 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 3),
	/* 56 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 3),
	/* 57 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 4),
	/* 58 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 4),
	/* 59 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 5),
	/* 60 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 5),
	/* 61 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 6),
	/* 62 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 6),
	/* 63 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 7),
	/* 64 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 7),
	/* 65 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 8),
	/* 66 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 8),
	/* 67 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 9),
	/* 68 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 9),
	/* 69 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::SKIP),
	/* 70 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::SKIP),
	/* 71 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::DRAW_TWO),
	/* 72 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::DRAW_TWO),
	/* 73 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::RESERVE),
	/* 74 */		Card(Card::COLOR::BLUE, Card::CARD_TYPE::RESERVE),

	/* 75 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 0),
	/* 76 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 1),
	/* 77 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 1),
	/* 78 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 2),
	/* 79 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 2),
	/* 80 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 3),
	/* 81 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 3),
	/* 82 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 4),
	/* 83 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 4),
	/* 84 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 5),
	/* 85 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 5),
	/* 86 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 6),
	/* 87 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 6),
	/* 88 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 7),
	/* 89 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 7),
	/* 90 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 8),
	/* 91 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 8),
	/* 92 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 9),
	/* 93 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 9),
	/* 94 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::SKIP),
	/* 95 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::SKIP),
	/* 96 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::DRAW_TWO),
	/* 97 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::DRAW_TWO),
	/* 98 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::RESERVE),
	/* 99 */		Card(Card::COLOR::GREEN, Card::CARD_TYPE::RESERVE),

	/* 100 */		Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD),
	/* 101 */		Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD),
	/* 102 */		Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD),
	/* 103 */		Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD),

	/* 104 */		Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD_DRAW_FOUR),
	/* 105 */		Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD_DRAW_FOUR),
	/* 106 */		Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD_DRAW_FOUR),
	/* 107 */		Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD_DRAW_FOUR),

};

Card::COLOR Card::getColor() const {
	return color;
}

Card::CARD_TYPE Card::getCardType() const {
	return cardType;
}

int Card::getCardId() const {
	return cardId;
}

int Card::getCardNum() const {
	return cardNum;
}

void Card::getAllCards(QVector<Card*>& cards)
{
	for (auto c : allCards) {
		cards.push_back(&c);
	}
}

Card* Card::getCardById(int cardId) {
	return &allCards[cardId];
}

bool Card::operator==(const Card& rhs) const {
	return color == rhs.color &&
		cardType == rhs.cardType &&
		cardNum == rhs.cardNum;
}

bool Card::operator!=(const Card& rhs) const {
	return !(rhs == *this);
}

int Card::getProcesser() const
{
	return processer;
}

void Card::setProcesser(int value)
{
	processer = value;
}

int Card::getTimestamp() const
{
	return timestamp;
}

void Card::setTimestamp(int value)
{
	timestamp = value;
}

Card::Card(COLOR color, CARD_TYPE cardType, int cardNum) : color(color), cardType(cardType), cardNum(cardNum), cardId(count++) {
	timestamp = 0;
	processer = 0;
}

#endif //UNO_CARDS_H

#include "cards.h"

int Card::count = 0;

QVector<Card*> Card::allCards = {};

void Card::CreateAllCards() {
	count = 0;
	QVector<Card*> Cardss = {
		/*  0 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 0),
		/*  1 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 1),
		/*  2 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 1),
		/*  3 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 2),
		/*  4 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 2),
		/*  5 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 3),
		/*  6 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 3),
		/*  7 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 4),
		/*  8 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 4),
		/*  9 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 5),
		/* 10 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 5),
		/* 11 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 6),
		/* 12 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 6),
		/* 13 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 7),
		/* 14 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 7),
		/* 15 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 8),
		/* 16 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 8),
		/* 17 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 9),
		/* 18 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 9),
		/* 19 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::SKIP),
		/* 20 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::SKIP),
		/* 21 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::DRAW_TWO),
		/* 22 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::DRAW_TWO),
		/* 23 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::RESERVE),
		/* 24 */		new Card(Card::COLOR::RED, Card::CARD_TYPE::RESERVE),

		/* 25 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 0),
		/* 26 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 1),
		/* 27 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 1),
		/* 28 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 2),
		/* 29 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 2),
		/* 30 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 3),
		/* 31 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 3),
		/* 32 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 4),
		/* 33 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 4),
		/* 34 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 5),
		/* 35 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 5),
		/* 36 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 6),
		/* 37 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 6),
		/* 38 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 7),
		/* 39 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 7),
		/* 40 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 8),
		/* 41 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 8),
		/* 42 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 9),
		/* 43 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::NUMBERIC, 9),
		/* 44 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::SKIP),
		/* 45 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::SKIP),
		/* 46 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::DRAW_TWO),
		/* 47 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::DRAW_TWO),
		/* 48 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::RESERVE),
		/* 49 */		new Card(Card::COLOR::YELLOW, Card::CARD_TYPE::RESERVE),

		/* 50 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 0),
		/* 51 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 1),
		/* 52 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 1),
		/* 53 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 2),
		/* 54 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 2),
		/* 55 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 3),
		/* 56 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 3),
		/* 57 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 4),
		/* 58 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 4),
		/* 59 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 5),
		/* 60 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 5),
		/* 61 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 6),
		/* 62 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 6),
		/* 63 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 7),
		/* 64 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 7),
		/* 65 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 8),
		/* 66 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 8),
		/* 67 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 9),
		/* 68 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::NUMBERIC, 9),
		/* 69 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::SKIP),
		/* 70 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::SKIP),
		/* 71 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::DRAW_TWO),
		/* 72 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::DRAW_TWO),
		/* 73 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::RESERVE),
		/* 74 */		new Card(Card::COLOR::BLUE, Card::CARD_TYPE::RESERVE),

		/* 75 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 0),
		/* 76 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 1),
		/* 77 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 1),
		/* 78 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 2),
		/* 79 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 2),
		/* 80 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 3),
		/* 81 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 3),
		/* 82 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 4),
		/* 83 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 4),
		/* 84 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 5),
		/* 85 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 5),
		/* 86 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 6),
		/* 87 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 6),
		/* 88 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 7),
		/* 89 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 7),
		/* 90 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 8),
		/* 91 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 8),
		/* 92 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 9),
		/* 93 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::NUMBERIC, 9),
		/* 94 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::SKIP),
		/* 95 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::SKIP),
		/* 96 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::DRAW_TWO),
		/* 97 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::DRAW_TWO),
		/* 98 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::RESERVE),
		/* 99 */		new Card(Card::COLOR::GREEN, Card::CARD_TYPE::RESERVE),

		/* 100 */		new Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD),
		/* 101 */		new Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD),
		/* 102 */		new Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD),
		/* 103 */		new Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD),

		/* 104 */		new Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD_DRAW_FOUR),
		/* 105 */		new Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD_DRAW_FOUR),
		/* 106 */		new Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD_DRAW_FOUR),
		/* 107 */		new Card(Card::COLOR::BLACK, Card::CARD_TYPE::WILD_DRAW_FOUR),

	};
	Card::allCards = Cardss;
}

void Card::deleteAllCards()
{
	for (int i = 0; i < 108; ++i) {
		delete Card::allCards[i];
	}
}

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

Card::COLOR Card::getColorById(int id)
{
	return COLOR(id/25);
}

Card::CARD_TYPE Card::getCardTypeById(int id)
{
	if (id >= 104 ) {
		return WILD_DRAW_FOUR;
	}
	else if (id >= 100) {
		return WILD;
	}
	else if (id % 25 < 19) {
		return NUMBERIC;
	}else if(id % 25 < 21){
		return SKIP;
	}else if(id % 25 < 21){
		return SKIP;
	}
	else if (id % 25 < 23) {
		return DRAW_TWO;
	}
	else if (id % 25 < 25) {
		return RESERVE;
	}
	assert(true);
	return WILD_DRAW_FOUR;
}

int Card::getCardNumById(int id)
{	
	if (getCardTypeById(id) == NUMBERIC) {
		return (id % 25 - 1) / 2 + 1;
	}
	else {
		return -1;
	}
	return 0;
}

void Card::getAllCards(QVector<Card*>& cards)
{
	for (int i = 0; i < 108;++i) {
		cards.push_back(Card::allCards[i]);
	}
}

Card* Card::getCardById(int cardId) {
	return Card::allCards[cardId];
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

Card::Card(COLOR color, CARD_TYPE cardType, int cardNum) : color(color), cardType(cardType), cardNum(cardNum), cardId(count++) {
	processer = -1;
}

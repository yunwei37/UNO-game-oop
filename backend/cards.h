//
// Created by ubuntu on 2020/6/9.
//

#ifndef UNO_CARDS_H
#define UNO_CARDS_H

#include <QVector>

class Card {

public:

	enum COLOR { RED, YELLOW, BLUE, GREEN, BLACK };
	enum CARD_TYPE { NUMBERIC, WILD, WILD_DRAW_FOUR, SKIP, RESERVE, DRAW_TWO };
	// get attrs
	COLOR getColor() const;
	CARD_TYPE getCardType() const;
	int getCardId() const;
	int getCardNum() const;

	static COLOR getColorById(int id);
	static CARD_TYPE getCardTypeById(int id);
	static int getCardNumById(int id);

	// get cards
	static void getAllCards(QVector<Card*>& cards);
	static Card* getCardById(int);

	// compares
	bool operator==(const Card& rhs) const;
	bool operator!=(const Card& rhs) const;

	int getProcesser() const;
	void setProcesser(int value);

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
};

#endif //UNO_CARDS_H

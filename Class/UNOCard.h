#include <iostream>
#include <string>
#include "UNOConstants.h"
using namespace std;

class UNOCard : public UNOConstants
{
public:
	int cardColor;
	string value;
	int type;
	UNOCard()
	{
	}
	UNOCard(int cardcolor, int cardType, string cardValue)
	{
		this->cardColor = cardcolor;
		this->value = cardValue;
		this->type = cardType;
	}
	void setColor(int newColor)
	{
		this.cardColor = newColor;
	}

	int getColor()
	{
		return cardColor;
	}

	void setValue(string newValue)
	{
		this.value = newValue;
	}

	string getValue()
	{
		return value;
	}
	void setType(int newType)
	{
		this.type = newType;
	}
	int getType()
	{
		return type;
	}
};
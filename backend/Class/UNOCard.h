#ifndef UNOCard_H
#define UNOCard_H

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

	UNOCard();

	UNOCard(int cardcolor, int cardType, string cardValue);

	void setColor(int newColor);

	int getColor();

	void setValue(string newValue);

	string getValue();

	void setType(int newType);

	int getType();
};
#endif
#include <iostream>
#include <string>
#include "UNOConstants.h"
using namespace std;

UNOCard::UNOCard()
{
}
UNOCard::UNOCard(int cardcolor, int cardType, string cardValue)
{
	this->cardColor = cardcolor;
	this->value = cardValue;
	this->type = cardType;
}
UNOCard::void setColor(int newColor)
{
	this.cardColor = newColor;
}

int UNOCard::getColor()
{
	return cardColor;
}

void UNOCard::setValue(string newValue)
{
	this.value = newValue;
}

string UNOCard::getValue()
{
	return value;
}
void UNOCard::setType(int newType)
{
	this.type = newType;
}
int UNOCard::getType()
{
	return type;
}
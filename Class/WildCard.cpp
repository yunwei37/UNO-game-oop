#include <iostream>
#include <string>
#include "UNOCard.h"
#include "UNOConstants.h"
#include "WildCard.h"

using namespace std;


WildCard::WildCard()
{
}

WildCard::WildCard(String cardValue) : UNOCard(cardColor, WILD, cardValue)
{
}
void WildCard::useWildColor(int wildColor)
{
	chosenColor = wildColor;
}

int WildCard::getWildColor()
{
	return chosenColor;
}

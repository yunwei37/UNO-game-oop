#ifndef WildCard_H
#define WildCard_H

#include <iostream>
#include <string>
#include "UNOCard.h"
#include "UNOConstants.h"
using namespace std;
class WildCard: public UNOCard 
{	
	private:
	
	int Function = 0;
	int  chosenColor;
	
	public:
	
	WildCard();
	
	WildCard(String cardValue):UNOCard(cardColor,WILD, cardValue);
	
	//choose a color for the wild card
	void useWildColor(int wildColor);
	
	//return the choosen color of the wild card
	int getWildColor();
};
#endif
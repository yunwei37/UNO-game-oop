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
	WildCard() 
	{
	}
	
	WildCard(String cardValue):UNOCard(cardColor,WILD, cardValue)
	{
	}
	void useWildColor(int wildColor)
	{
		chosenColor = wildColor;
	}
	
	int getWildColor()
	{
		return chosenColor;
	}
}

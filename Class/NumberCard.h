#include <iostream>
#include <string>
#include "UNOCard.h"
#include "UNOConstants.h"
using namespace std;
class NumberCard: public UNOCard
{
	public: 
	NumberCard()
	{
	}
	NumberCard(int cardColor, int cardValue):UNOCard(cardColor, NUMBERS, cardValue)
	{		
	}
};
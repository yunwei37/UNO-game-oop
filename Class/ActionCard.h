#include <iostream>
#include <string>
#include "UNOCard.h"
#include "UNOConstants.h"
using namespace std;

class ActionCard : public UNOCard
{
private:
	int Function = 0;

public:
	ActionCard()
	{
	}

	ActionCard(Color cardColor, String cardValue) : UNOCard(cardColor, ACTION, cardValue)
	{
	}
}

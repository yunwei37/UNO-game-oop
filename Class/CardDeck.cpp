#include <iostream>
#include <vector>
#inlcude < stack>
#include <string>
#include "UNOCard.h"
#include "GameConstants.h"
#include "CardDeck.h"

using namespace std;

CardDeck::CardDeck()
{
	addCards();
}
void CardDeck::addCards()
{
	for (int color = 0; color < 4; color++)
	{

		//Create 76 NumberCards --> doubles except 0s.
		for (int num = 0; num < 10; num++)
		{
			int i = 0;
			do
			{
				//mention here
				UNOcards.push_back(new NumberCard(color, num));
				i++;
			} while (num != 0 && i < 2);
		}

		//Create 24 ActionCards --> everything twice
		for (int type = 0; type < 3; type++)
		{
			for (int i = 0; i < 2; i++)
				UNOcards.push_back(new ActionCard(color, ActionTypes[type]));
		}
	}

	for (type = 0; type < 2; type++)
	{
		for (int i = 0; i < 4; i++)
		{
			UNOcards.push_back(new WildCard(WildTypes[type]));
		}
	}
}
vector<UNOCard> CardDeck::getCards()
{
	return UNOcards;
}
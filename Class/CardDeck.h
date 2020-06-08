#ifndef CardDeck_H
#define CardDeck_H

#include <iostream>
#include<vector>
#inlcude <stack>
#include <string>
#include "UNOCard.h"
#include "GameConstants.h"

using namespace std;

class CardDeck: public GameConstants
{
	private:
	
	vector<NumberCard> numberCards;
    vector<ActionCard> actionCards;
	vector<WildCard> wildCards;
	vector<UNOCard> UNOcards;
	
	
	public:
	
	CardDeck();
	
	void addCards();
	
	vector<UNOCard> getCards();

};

#endif
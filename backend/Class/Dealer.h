#ifndef Dealer_H
#define Dealer_H

#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <time>
#include "UNOCard.h"
#include "CardDeck.h"
#include "GameConstants.h"

using namespace std;

class Dealer : public GameConstants
{
private:
	CardDeck cardDeck;
	stack<UNOCard> CardStack;

public:
	Dealer();
	//shuffle cards

	stack<UNOCard> shuffle();

	//spread out cards to players
	void spreadOut(vector<Player> &players);

	UNOCard getCard();
};
#endif
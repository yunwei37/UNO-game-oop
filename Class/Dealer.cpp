#include <iostream>
#include <vector>
#inlcude <stack>
#include <cstdlib>
#include <time>
#include "UNOCard.h"
#include "CardDeck.h"
#include "GameConstants.h"
#include "Dealer.h"

using namespace std;


	Dealer::Dealer()
	{
	}	
	
    //shuffle card
	stack<UNOCard> Dealer::shuffle()
	{
		vector<UNOCard> shuffledCards;
		vector<UNOCard> DeckOfCards(cardDeck.getCards());
		while(!DeckOfCards.empty())
		{
			int totalCards = DeckOfCards.size();
			srand(int(time(0)));
			int pos = rand()%totalCards;
			UNOCard randomCard = DeckOfCards[pos];
			DeckOfCards.erase (DeckOfCards.begin()+pos);
			shuffledCards.push_back(randomCard);
		}
		vector<UNOCard>::iterator card = shuffledCards.begin();
		while( card!= shuffledCards.end()) 
		{
			CardStack.push(*card);
			card++;
        }
		return CardStack;
	}
	
	//spread out card
	void Dealer::spreadOut(vector<Player>&players)
	{
		int i;
		for(i=1;i<=FIRSTHAND;i++)
		{
			vector<Player>::iterator p = players.begin();
			while( p!= players.end()) 
			{
				(*p).obtainCard(CardStack.pop());
				p++;
            }
		}
	}
	
	UNOCard Dealer::getCard()
	{
		UNOCard temp=CardStack.top();
		CardStack.pop();
		return temp;
	}
#include <iostream>
#include<vector>
#inlcude <stack>
#include <string>
#include "UNOCard.h"

using namespace std;

class Player
{
	public:
	vector<UNOCard> myCards;
	
	protected:
	string name;
	bool isMyturn = false;
	bool saidUNO = false;
	int playedcards = 0;
	
	public:
	Player()
	{
	}
	Player(string player)
	{
		name=player;
	}
	string getName()
	{
		return this->name;
	}
	void obtainCard(UNOCard card)
	{
		vec.push_back(card);
	}
	vector<UNOCard> getAllCard()
	{
		return myCards;
	}
	int getTotalCards()
	{
		return myCards.size();
	}
	bool hasCard(UNOCard thisCard)
	{
		return (count(myCards.begin(),myCards.end(),thisCard))? true : false;		
	}
	void removeCard(UNOCard thisCard)
	{
		vector<UNOCard>::iterator newEnd(remove(myCards.begin(),myCards.end(),thisCard));
        myCards.erase(newEnd,myCards.end());
		playedCards++;
	}
	int totalPlayedCards()
	{
		return playedCards;
	}
	
	void toggleTurn()
	{
		isMyTurn = (isMyTurn) ? false : true;
	}
	
	bool isMyTurn()
	{
		return isMyTurn;
	}
	bool hasCards()
	{
		return (myCards.size()) ? true : false;
	}
	bool getSaidUNO()
	{
		return saidUNO;
	}
	
	void saysUNO()
	{
		saidUNO = true;
	}
	
	void setSaidUNOFalse()
	{
		saidUNO = false;
	}
};
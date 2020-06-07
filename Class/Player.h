#ifndef PLAYER_H
#define PLAYER_H
 
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
	
	Player();
	
	Player(string player);
	
	string getName();
	
	void obtainCard(UNOCard card);
	
	vector<UNOCard> getAllCard();
	
	int getTotalCards();
	
	bool hasCard(UNOCard thisCard);
	
	void removeCard(UNOCard thisCard);
	
	int totalPlayedCards();
	
	void toggleTurn();
	
	bool isMyTurn();
	
	bool hasCards();
	
	bool getSaidUNO();
	
	void saysUNO();
	
	void setSaidUNOFalse();
};

#endif
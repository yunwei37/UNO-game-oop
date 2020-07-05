#include <iostream>
#include<vector>
#include <stack>
#include <string>
#include "UNOCard.h"
#include "Player.h"

using namespace std;

	Player::Player()
	{
	}
	
	Player::Player(string player)
	{
		name=player;
	}
	
	string Player::getName()
	{
		return this->name;
	}
	
	void Player::obtainCard(UNOCard card)
	{
		vec.push_back(card);
	}
	
	vector<UNOCard> Player::getAllCard()
	{
		return myCards;
	}
	
	int Player::getTotalCards()
	{
		return myCards.size();
	}
	
	bool Player::hasCard(UNOCard thisCard)
	{
		return (count(myCards.begin(),myCards.end(),thisCard))? true : false;		
	}
	
	void Player::removeCard(UNOCard thisCard)
	{
		vector<UNOCard>::iterator newEnd(remove(myCards.begin(),myCards.end(),thisCard));
        myCards.erase(newEnd,myCards.end());
		playedCards++;
	}
	
	int Player::totalPlayedCards()
	{
		return playedCards;
	}
	
	void Player::toggleTurn()
	{
		isMyTurn = (isMyTurn) ? false : true;
	}
	
	bool Player::isMyTurn()
	{
		return isMyTurn;
	}
	bool Player::hasCards()
	{
		return (myCards.size()) ? true : false;
	}
	bool Player::getSaidUNO()
	{
		return saidUNO;
	}
	
	void Player::saysUNO()
	{
		saidUNO = true;
	}
	
	void Player::setSaidUNOFalse()
	{
		saidUNO = false;
	}
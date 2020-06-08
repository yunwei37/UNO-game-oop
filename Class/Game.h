#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#inlcude < stack>
#include <string>

#include "UNOCard.h"

#include "ActionCard.h"
#include "NumberCard.h"
#include "WildCard.h"
#include "CardDeck.h"

#include "GameConstants.h"
#include "Dealer.h"
#include "Player.h"
#include "PC.h"

using namespace std;

class Game : public GameConstants
{
private:
	vector<Player> players;
	stack<UNOCard> cardStack;
	bool isOver;
	int GAMEMODE;
	PC *pc;
	Dealer *dealer;

public:
	Game(int Mode);
	vector<Player> getPlayers();
	UNOCard getCard();
	void removePlayedCard(UNOCard playedCard);
	void drawCard(UNOCard topCard);
	void switchTurn();
	//Draw cards x times
	void drawPlus(int times);
	//response whose turn it is
	void whoseTurn();
	//return if the game is over
	bool isOver();
	int remainingCards();
	//Check if this card can be played
	bool canPlay(UNOCard topCard, UNOCard newCard);
	//Check whether the player said or forgot to say UNO
	void checkUNO();
	void setSaidUNO();
	bool isPCsTurn();
	//if it's PC's turn, play it for pc
	void playPC(UNOCard topCard);
};

#endif
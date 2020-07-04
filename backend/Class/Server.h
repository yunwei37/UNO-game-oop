#ifndef Server_H
#define Server_H

#include <iostream>
#include <vector>
#inlcude <stack>
#include <string>
#include <cstdlib>
#include <time>

#include "UNOCard.h"

#include "ActionCard.h"
#include "NumberCard.h"
#include "WildCard.h"
#include "CardDeck.h"

#include "GameConstants.h"
#include "Dealer.h"
#include "Player.h"
#include "PC.h"
#include "Game.h"


using namespace std;

class Server :public GameConstants
{
	private:
	Game* game;
	stack<UNOCard> playedCards;
	bool canPlay;
	int mode;
	
	public:
	
	Server();
	
	//return mode
	int requestMode();
	
	//play a card
	void playThisCard(UNOCard clickedCard) ;
	
	//check game over
	bool checkResults();
	
	//Is his turn ?
    bool isHisTurn(UNOCard clickedCard) ;

	//check if play this card fit to rules 
	bool isValidMove(UNOCard playedCard) ;

	// Action card
	void performAction(ActionCard actionCard) ;
	
    //Wild Card
	void performWild(WildCard functionCard) ;
	
	//player request to draw a card (cause he has no card to play
	void requestCard() ;
	
	//return top of the stack of played cards
	UNOCard peekTopCard();
    
	//said UNO
    void submitSaidUNO() ;
};
#endif
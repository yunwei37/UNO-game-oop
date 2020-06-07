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
#include "Server.h"

using namespace std;

	Server::Server()
	{
		mode = requestMode();                 //Game Mode confirmed
		game = new Game(mode);                //shuffle card & spread out cards to players 
		
		UNOCard firstCard = game.getCard();   //the first card of game, from the dealer		
		playedCards.add(firstCard);
		game.whoseTurn();                     //print the name of players if it's his turn 
		canPlay = true;
	}
	//return mode
	int Server::requestMode() 
	{
		int n;
		cout<<"Enter mode [0:PvC   1:PvP]: ";
		cin>>n;
		cout<<endl;
		return GAMEMODES[n];
	}
	//play a card
	void Server::playThisCard(UNOCard clickedCard) 
	{
		// Is his turn ?
		if (!isHisTurn(clickedCard)) 
		{
			cout<<"It's not your turn"<<endl;
		} 
		else 
		{
			// confirm would  play the card would break the rule
			if (isValidMove(clickedCard)) 
			{
				playedCards.add(clickedCard);
				game.removePlayedCard(clickedCard);
				//acton card
				switch (clickedCard.getType()) 
				{
				case ACTION:
					performAction(clickedCard);
					break;
				case WILD:
					performWild((WildCard) clickedCard);
					break;
				default:
					break;
				}
				game.switchTurn();
				checkResults();
			} 
			else 
			{
				cout<<"invalid move";
			}
		}
		if(mode==vsPC && canPlay)
		{
			if(game.isPCsTurn())
			{
				game.playPC(peekTopCard());
			}
		}
	}
	//check game over
	bool Server::checkResults() 
	{
		if (game.isOver()) 
		{
			canPlay = false;
			cout<<"GAME OVER"<<endl;
			return false;
		}
		else
			return true;
	}
	
	//Is his turn ?
    bool Server::isHisTurn(UNOCard clickedCard) 
	{
		vector<Player>::iterator p = game.getPlayers().begin();
		while( p!= game.getPlayers().end()) 
		{
			if ((*p).hasCard(clickedCard) &&(*p).isMyTurn())
				return true;
			p++;
		}
		return false;
	}

	//check if play this card fit to rules 
	bool Server::isValidMove(UNOCard playedCard) 
	{
		UNOCard topCard = peekTopCard();
		if ((playedCard.getColor()==topCard.getColor())||(playedCard.getValue()==topCard.getValue())) 
		{
			return true;
		}
		else if (playedCard.getType() == WILD) 
		{
			return true;
		} 
		else if (topCard.getType() == WILD) 
		{
			int color = ((WildCard) topCard).getWildColor();
			if (color==playedCard.getColor())
				return true;
		}
		return false;
	}

	// Action card
	void Server::performAction(ActionCard actionCard) 
	{
		// Punishment: draw another two card
		if (actionCard.getValue()==DRAW2PLUS)
			game.drawPlus(2);
		else if (actionCard.getValue()==REVERSE)
			game.switchTurn();
		else if (actionCard.getValue()==SKIP)
			game.switchTurn();
	}
    //Wild Card
	void Server::performWild(WildCard functionCard) 
	{		
		int chosenColor;
		if(mode==1 && game.isPCsTurn())
		{
			srand(int(time(0)));
			int random = rand()%4;
			functionCard.useWildColor(UNO_COLORS[Math.abs(random)]);
		}
		else
		{	
            cout<<"Choose a color:";
			cin>>chosenColor;
			functionCard.useWildColor(chosenColor);
		}		
		if (functionCard.getValue()==W_DRAW4PLUS)
			game.drawPlus(4);
	}
	//player request to draw a card (cause he has no card to play
	void Server::requestCard() 
	{
		game.drawCard(peekTopCard());	
		if(mode==vsPC && canPlay)
		{
			if(game.isPCsTurn())
				game.playPC(peekTopCard());
		}
	}
	//return top of the stack of played cards
	UNOCard Server::peekTopCard() 
	{
		return playedCards.top();
	}
     //said UNO
    void Server::submitSaidUNO() 
	{
		game.setSaidUNO();
	}
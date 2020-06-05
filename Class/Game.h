#include <iostream>
#include <vector>
#inlcude <stack>
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

class Game: public GameConstants
{
	private:
	vector<Player> players;
    stack<UNOCard> cardStack;
	bool isOver;
	int GAMEMODE;
	PC *pc;
	Dealer *dealer;
	public:
	Game(int Mode)
	{
		GAMEMODE=Mode;
		string name=(GAMEMODE==MANUAL) ? "Player 1":"PC";
        string name2 = "Player 2";
		if(GAMEMODE==vsPC)
			pc = new PC();
		Player *player1 = (GAMEMODE==vsPC) ? pc : new Player(name);
		Player *player2 = new Player(name2);		
		player2->toggleTurn();				//Initially, player2's turn		
			
		players.push_back(player1);
		players.push_back(player2);
		//Create Dealer
		dealer = new Dealer();
		cardStack = dealer->shuffle();
		dealer->spreadOut(players);
		
		isOver = false;
		
	}
	vector<Player> getPlayers()
	{
		return players;
	}
	UNOCard getCard()
	{
		return dealer->getCard();
		
	}
	void removePlayedCard(UNOCard playedCard) 
	{
		
		vector<Player>::iterator p = players.begin();
		while( p!= players.end()) 
		{
			if ((*p).hasCard(playedCard))
			{
				(*p).removeCard(playedCard);	
				if ((*p).getTotalCards() == 1 && !(*p).getSaidUNO()) 
				{
					cout<<(*p).getName()<<" Forgot to say UNO"<<endl;
					(*p).obtainCard(getCard());
					(*p).obtainCard(getCard());
				}
				else if((*p).getTotalCards()>2)
				{
					(*p).setSaidUNOFalse();
				}
			}	
            p++;			
		}
	}
	//give player a card
	void drawCard(UNOCard topCard) 
	{
		bool canPlay = false;
		vector<Player>::iterator p = players.begin();
		while( p!= players.end()) 
		{
			if ((*p).isMyTurn()) 
			{
				UNOCard newCard = getCard();
				(*p).obtainCard(newCard);
				canPlay = canPlay(topCard, newCard);
				break;
			}
			p++;
		}
		if (!canPlay)
			switchTurn();
	}

	void switchTurn() 
	{
		vector<Player>::iterator p = players.begin();
		while( p!= players.end()) 
		{
			(*p).toggleTurn();
			p++;
		}
		whoseTurn();
	}
	//Draw cards x times
	void drawPlus(int times) 
	{
		vector<Player>::iterator p = players.begin();
		while( p!= players.end()) 
		{
			if (!(*p).isMyTurn()) 
			{
				for (int i = 1; i <= times; i++)
					(*p).obtainCard(getCard());
			}
			p++:
		}
	}
	//response whose turn it is
	void whoseTurn() 
	{
		vector<Player>::iterator p = players.begin();
		while( p!= players.end()) 
		{
			if ((*p).isMyTurn())
		    {
				cout<<(*p).getName()<<"'s Turn"<<endl;;
			}
			p++;
		}
	}
	//return if the game is over
	bool isOver() 
	{	
		if(cardStack.empty())
		{
			isOver= true;
			return isOver;
		}
		vector<Player>::iterator p = players.begin();
		while( p!= players.end()) 
		{
			if (!(*p).hasCards()) 
			{
				isOver = true;
				break;
			}
			p++;
		}
		return isOver;
	}
	int remainingCards() 
	{
		return cardStack.size();
	}
	//Check if this card can be played
	bool canPlay(UNOCard topCard, UNOCard newCard) 
	{
		// Color or value matches
		if (topCard.getColor().equals(newCard.getColor())|| topCard.getValue().equals(newCard.getValue()))
			return true;
		// if chosen wild card color matches
		else if (topCard.getType() == WILD)
			return ((WildCard) topCard).getWildColor().equals(newCard.getColor());
		// suppose the new card is a wild card
		else if (newCard.getType() == WILD)
			return true;
		// else
		return false;
	}
	//Check whether the player said or forgot to say UNO
	void checkUNO() 
	{
		vector<Player>::iterator p = players.begin();
		while( p!= players.end()) 
		{
			if ((*p).isMyTurn()) 
			{
				if ((*p).getTotalCards() == 1 && !(*p).getSaidUNO()) 
				{
					cout<<(*p).getName()<<" Forgot to say UNO"<<endl;
					(*p).obtainCard(getCard());
					(*p).obtainCard(getCard());
				}
			}
			p++;
		}		
	}
	void setSaidUNO() 
	{
		vector<Player>::iterator p = players.begin();
		while( p!= players.end()) 
		{
			if ((*p).isMyTurn()) 
			{
				if ((*p).getTotalCards() == 2) 
				{
					(*p).saysUNO();
					cout<<(*p).getName()<<" Said UNO"<<endl;
				}
			}
			p++;
		}
	}
	bool isPCsTurn()
	{
		if(pc->isMyTurn())
		{
			return true;
		}
		return false;
	}
	//if it's PC's turn, play it for pc
	void playPC(UNOCard topCard) 
	{		
		
		if (pc->isMyTurn()) 
		{
			bool done = pc->play(topCard);
			if(!done)
				drawCard(topCard);
		}
	}	
};
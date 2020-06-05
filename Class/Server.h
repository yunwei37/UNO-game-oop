#include <iostream>
#include <vector>
#inlcude < stack>
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

class Server : public GameConstants
{
private:
	Game *game;
	stack<UNOCard> playedCards;
	bool canPlay;
	int mode;

public:
	Server()
	{
		mode = requestMode();
		game = new Game(mode);
		// First Card
		UNOCard firstCard = game.getCard();
		playedCards.add(firstCard);
		game.whoseTurn();
		canPlay = true;
	}
	//return if it's 2-Player's mode or PC-mode
	int requestMode()
	{
		int n;
		Object[] options = {"vs PC", "Manual"};
		/////////////////////
		cout << "Input Mode:";
		cin >> n;
		cout << endl;
		return GAMEMODES[n];
	}
	//request to play a card
	void playThisCard(UNOCard clickedCard)
	{
		// Check player's turn
		if (!isHisTurn(clickedCard))
		{
			cout << "It's not your turn" << endl;
		}
		else
		{
			// Card validation
			if (isValidMove(clickedCard))
			{
				playedCards.add(clickedCard);
				game.removePlayedCard(clickedCard);
				// function cards ?
				switch (clickedCard.getType())
				{
				case ACTION:
					performAction(clickedCard);
					break;
				case WILD:
					performWild((WildCard)clickedCard);
					break;
				default:
					break;
				}
				game.switchTurn();
				checkResults();
			}
			else
			{
				cout << "invalid move";
			}
		}
		if (mode == vsPC && canPlay)
		{
			if (game.isPCsTurn())
			{
				game.playPC(peekTopCard());
			}
		}
	}
	//Check if the game is over
	void checkResults()
	{
		if (game.isOver())
		{
			canPlay = false;
			cout << "GAME OVER" << endl;
		}
	}

	//check player's turn
	bool isHisTurn(UNOCard clickedCard)
	{
		vector<Player>::iterator p = game.getPlayers().begin();
		while (p != game.getPlayers().end())
		{
			if ((*p).hasCard(clickedCard) && (*p).isMyTurn())
				return true;
			p++;
		}
		return false;
	}

	//check if it is a valid card
	bool isValidMove(UNOCard playedCard)
	{
		UNOCard topCard = peekTopCard();
		if ((playedCard.getColor() == topCard.getColor()) || (playedCard.getValue() == topCard.getValue()))
		{
			return true;
		}
		else if (playedCard.getType() == WILD)
		{
			return true;
		}
		else if (topCard.getType() == WILD)
		{
			int color = ((WildCard)topCard).getWildColor();
			if (color == playedCard.getColor())
				return true;
		}
		return false;
	}

	// ActionCards
	void performAction(ActionCard actionCard)
	{
		// Draw2PLUS
		if (actionCard.getValue() == DRAW2PLUS)
			game.drawPlus(2);
		else if (actionCard.getValue() == REVERSE)
			game.switchTurn();
		else if (actionCard.getValue() == SKIP)
			game.switchTurn();
	}

	void performWild(WildCard functionCard)
	{
		//System.out.println(game.whoseTurn());
		int chosenColor;
		if (mode == 1 && game.isPCsTurn())
		{
			srand(int(time(0)));
			int random = rand() % 4;
			functionCard.useWildColor(UNO_COLORS[Math.abs(random)]);
		}
		else
		{
			cout << "Choose a color:";
			cin >> chosenColor;
			functionCard.useWildColor(chosenColor);
		}
		if (functionCard.getValue() == W_DRAW4PLUS)
			game.drawPlus(4);
	}

	void requestCard()
	{
		game.drawCard(peekTopCard());
		if (mode == vsPC && canPlay)
		{
			if (game.isPCsTurn())
				game.playPC(peekTopCard());
		}
		session.refreshPanel();
	}
	UNOCard peekTopCard()
	{
		return playedCards.peek();
	}

	void submitSaidUNO()
	{
		game.setSaidUNO();
	}
};
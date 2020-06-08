#include <iostream>
#include <vector>
#include < stack>
#include "UNOCard.h"
#include "WildCard.h"
#include "GameConstants.h"
#include "PC.h"

using namespace std;

PC::PC()
{
	setName("PC");
}
PC::PC(Player player)
{
}
//PC plays a card
bool PC::play(UNOCard topCard)
{
	bool done = false;
	Color color = topCard.getColor();
	String value = topCard.getValue();

	if (topCard.getType() == WILD)
	{
		color = ((WildCard)topCard).getWildColor();
	}
	for (UNOCard card : getAllCards())
	{
		if (card.getColor().equals(color) || card.getValue().equals(value))
		{
			//
			playthiscard(card); //still wait to realize
			//
			done = true;
			break;
		}
	}

	// if no card was found, play wild card
	if (!done)
	{
		for (UNOCard card : getAllCards())
		{
			if (card.getType() == WILD)
			{
				////////////
				playthiscard(card);
				////////////
				done = true;
				break;
			}
		}
	}
	if (getTotalCards() == 1 || getTotalCards() == 2)
		saysUNO();
	return done;
}
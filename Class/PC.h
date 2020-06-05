#include <iostream>
#include<vector>
#inlcude <stack>
#include "UNOCard.h"
#include "WildCard.h"
#include "GameConstants.h"

using namespace std;

class PC: public Player,public GameConstants
{
	public:
	PC() 
	{
		setName("PC");
	}
    PC(Player player) 
	{
	}
	//PC plays a card
	bool play(UNOCard topCard) 
	{
		bool done = false;
		Color color = topCard.getColor();
		String value = topCard.getValue();
		
		if(topCard.getType()==WILD)
		{
			color = ((WildCard) topCard).getWildColor();			
		}
		for (UNOCard card : getAllCards()) 
		{
			if (card.getColor().equals(color) || card.getValue().equals(value)) 
			{	
				/*
	              func  PLAYTHISCARD()  wait to complete
	            */
				playthiscard(card);
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
					/*
	                func  PLAYTHISCARD()  wait to complete
	                */
					playthiscard(card);
					done = true;
					break;
				}
			}
		}
		if(getTotalCards()==1 || getTotalCards()==2)
			saysUNO();
		return done;
	}
};
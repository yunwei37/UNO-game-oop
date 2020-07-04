#ifndef PC_H
#define PC_H 

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
	PC();
    PC(Player player);
	//PC plays a card
	bool play(UNOCard topCard);
};


#endif
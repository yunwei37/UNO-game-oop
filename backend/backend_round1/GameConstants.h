#include <iostream>
#include <string>

using namespace std;

class GameConstants : public UNOConstants
{
public:
	int TOTAL_CARDS = 108;
	int FIRSTHAND = 8;
	int UNO_COLORS[4] = {0, 1, 2, 3}; //0 RED, 1 BLUE, 2 GREEN, 3 YELLOW
	int WILD_CARDCOLOR = 4;			  //4 BLACK
	int UNO_NUMBERS[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	string ActionTypes[3] = {REVERSE, SKIP, DRAW2PLUS};
	string WildTypes[2] = {W_COLORPICKER, W_DRAW4PLUS};
	int vsPC = 1;
	int MANUAL = 2;
	int GAMEMODES[2] = {vsPC, MANUAL};
}

#include "botLvl1.h"
#include "move.h"
#include "board.h"

using namespace std;

BotLvl1::~BotLvl1(){}

BotLvl1::BotLvl1(char colour){
	allegiance = colour;
}

Move BotLvl1::getMove(Board &b) {
	vector<Move> legal_moves = b.getAllPossibleMovesByColour(allegiance);
	int randNum = rand() % legal_moves.size();
	return legal_moves[randNum];
}
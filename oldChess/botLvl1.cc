#include "botLvl1.h"
#include "move.h"
#include "board.h"

using namespace std;

BotLvl1::~BotLvl1(){}

Move BotLvl1::getMove(Board &b) {
	vector<Move> legal_moves = b.getAllLegalMovesByColour(allegiance);
	int randNum = rand() % legal_moves.size();
	return legal_moves[randNum];
}
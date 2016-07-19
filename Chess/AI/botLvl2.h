#ifndef LVL_2AI
#define LVL_2AI

#include "abstractAI.h"

class Move;
class Board;

class BotLvl2: public AbstractAI{
	vector<Move> getCapturingandCheckingMoves(vector<Move> availableMoves);
	Move getMove(Board &b)

};

#endif
#ifndef LVL_2AI
#define LVL_2AI

#include "abstractAI.h"

class Move;
class Board;

//Level 2: prefers capturing moves and checks over other moves.
class BotLvl2: public AbstractAI{
public:
	~BotLvl2();
	vector<Move> getCapturingandCheckingMoves(vector<Move> availableMoves);
	Move randomLegalMove(Board &b);
	Move getMove(Board &b) override;

};

#endif
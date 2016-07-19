#ifndef LVL_3AI
#define LVL_3AI

#include "abstractAI.h"

class BotLvl3: public AbstractAI{
	vector<ChessPiece *> getMyThreatenedPieces(Board &b);
	bool isMoveSafe(Move m);
	vector<Move> getCapturingandCheckingMoves(vector<Move> availableMoves);
	Move getMove(Board &b) override;
	
};

#endif
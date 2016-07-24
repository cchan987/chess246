#ifndef LVL_3AI
#define LVL_3AI

#include "abstractAI.h"

// Level 3: prefers avoiding capture, capturing moves, and checks
class BotLvl3: public AbstractAI{
public:
	~BotLvl3();
	vector<ChessPiece *> getMyThreatenedPieces(Board &b);
	bool isMoveSafe(Move m);
	bool isSquareThreatened(Posn p)
	vector<Move> getSalvagingMoves(Board &b);
	vector<ChessPiece *> getMyThreatenedPieces(Board &b);
	vector<Move> getCapturingandCheckingMoves(vector<Move> availableMoves);
	Move getMove(Board &b) override;
	
};

#endif
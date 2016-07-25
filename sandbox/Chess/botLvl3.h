#ifndef LVL_3AI
#define LVL_3AI

#include "abstractAI.h"

// Level 3: prefers avoiding capture, capturing moves, and checks
class BotLvl3: public AbstractAI{
public:
	~BotLvl3();
	BotLvl3(char colour);
	bool isSquareThreatened(Posn p, Board &b);
	std::vector<Move> getSalvagingMoves(Board &b);
	std::vector<ChessPiece *> getMyThreatenedPieces(Board &b);
	std::vector<Move> getCapturingandCheckingMoves(Board &b);
	Move getMove(Board &b) override;
	
};

#endif
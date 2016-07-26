#ifndef ABSTRACT_AI
#define ABSTRACT_AI
#include <vector>
#include "move.h"

class Board;

class AbstractAI {
	std::vector<Move> getAllLegalMovesByColour(char colour);
public:
	char allegiance;
	virtual ~AbstractAI();
	virtual Move getMove(Board &b) = 0;
};
#endif
#ifndef LVL_1AI
#define LVL_1AI

#include "abstractAI.h"

class Board;
class Move;

class BotLvl1: public AbstractAI{
	Move getMove(Board &b) override;
};

#endif
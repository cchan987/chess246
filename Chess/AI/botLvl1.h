#ifndef LVL_1AI
#define LVL_1AI

#include "abstractAI.h"

class Board;

class BotLvl1: public AbstractAI{
	void getMove(Board &b) override;
};

#endif
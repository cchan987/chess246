#include "botLvl2.h"
#include "move.h"
#include "board.h"

using namespace std;

BotLvl2::~BotLvl2(){}
BotLvl2::BotLvl2(char colour){allegiance = colour;}

vector<Move> BotLvl2::getCapturingandCheckingMoves(Board &b) {
	vector<Move> availableMoves = b.getAllPossibleMovesByColour(allegiance);
	vector<Move> filteredMoves;
	for (unsigned int i = 0; i < availableMoves.size(); ++i) {
		if (b.isCheckingMove(availableMoves[i]) || availableMoves[i].getIsCapturingMove()) {
			filteredMoves.emplace_back(availableMoves[i]);
		}
	}
	return filteredMoves;
}

Move BotLvl2::randomLegalMove(Board &b) {
	vector<Move> legal_moves = b.getAllPossibleMovesByColour(allegiance);
	int randNum = rand() % legal_moves.size();
	return legal_moves[randNum];
}

Move BotLvl2::getMove(Board &b) {
	vector<Move> applicableMoves = getCapturingandCheckingMoves(b);
	if (applicableMoves.size() > 0) {
		int randNum = rand() % applicableMoves.size();
		return applicableMoves[randNum];
	}
	else {
		return randomLegalMove(b);
	}
}
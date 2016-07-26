#include "botLvl2.h"
#include "move.h"
#include "Board.h"

using namespace std;

BotLvl2::~BotLvl2();

vector<Move> BotLvl2::getCapturingandCheckingMoves(Board &b) {
	vector<Move> availableMoves = b.getAllLegalMovesByColour(allegiance);
	vector<Move> filteredMoves;
	for (int i = 0; i < availableMoves.size(); ++i) {
		if (b.isCheckingMove(availableMoves[i]) || b.isCapturingMove(availableMoves[i])) {
			filteredMoves.emplace_back(availableMoves[i]);
		}
	}
	return filteredMoves;
}

Move BotLvl2::randomLegalMove(Board &b) {
	vector<Move> legal_moves = b.getAllLegalMovesByColour(allegiance);
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
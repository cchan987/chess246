#include "botLvl2.h"
#include "move.h"

using namespace std;
vector<Move> getCapturingandCheckingMoves(Board &b) {
	vector<Move> availableMoves = b.getAllLegalMovesByColour(allegiance);
	vector<Move> filteredMoves;
	for (int i = 0; i < availableMoves.size(); ++i) {
		if (b.isCheckingMove(availableMoves[i]) || b.isCapturingMove(availableMoves[i])) {
			filteredMoves.emplace_back(availableMoves[i]);
		}
	}
	return filteredMoves;
}

Move randomLegalMove(Board &b) {
	vector<Move> legal_moves = b.getAllLegalMovesByColour(allegiance);
	int randNum = rand() % legal_moves.size();
	return legal_moves[randNum];
}

Move getMove(Board &b) {
	vector<Move> applicableMoves = getCapturingandCheckingMoves(b);
	if (applicableMoves.size() > 0) {
		int randNum = rand() % applicableMoves.size();
		return applicableMoves[randNum];
	}
	else {
		return randomLegalMove(b);
	}
}
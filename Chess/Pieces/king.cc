#include "king.h"
#include "move.h"
#include "chesspiece.h"

void King::setMoved() {
	hasBeenMoved = true;
}

bool King::hasBeenMoved() {
	return hasBeenMoved;
}

char King::getPieceType() {
	return 'K';
}

vector<Move> King::getPossibleMoves() {
	vector<Move> PossibleMoves;
	int row = location.getRow();
	int col = location.getCol();

	PossibleMoves.emplace_back(Move(this, Posn(row + 1, col)));
	PossibleMoves.emplace_back(Move(this, Posn(row - 1, col)));
	PossibleMoves.emplace_back(Move(this, Posn(row, col + 1)));
	PossibleMoves.emplace_back(Move(this, Posn(row, col - 1)));

	if (hasBeenMoved == false) { // Can castle
		PossibleMoves.emplace_back(Move(this, Posn(row, col + 2)));
		PossibleMoves.emplace_back(Move(this, Posn(row, col - 2)));
	}
	
	return PossibleMoves;
}
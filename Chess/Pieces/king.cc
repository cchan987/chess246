#include "king.h"
#include "move.h"
#include "chesspiece.h"

void King::setMoved() {
	hasBeenMoved = true;
}

bool King::getHasBeenMoved() const {
	return hasBeenMoved;
}

char King::getPieceType() const {
	return 'K';
}

void King::setPosition(Posn p){
	setMoved();
	location = p;
}

vector<Move> King::getPossibleMoves() const {
	vector<Move> PossibleMoves;
	int row = location.getRow();
	int col = location.getCol();

	if (row < 7) {
		PossibleMoves.emplace_back(Move(this, Posn(row + 1, col)));
	}
	if (row > 0) {
		PossibleMoves.emplace_back(Move(this, Posn(row - 1, col)));
	}
	if (col < 7) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col + 1)));
	}
	if (col > 0 ) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col - 1)));
	}

	if (hasBeenMoved == false) { // Can castle
		PossibleMoves.emplace_back(Move(this, Posn(row, col + 2)));
		PossibleMoves.emplace_back(Move(this, Posn(row, col - 2)));
	}

	return PossibleMoves;
}
#include "rook.h"
#include "move.h"
#include "chesspiece.h"

void Rook::setMoved() {
	hasBeenMoved = true;
}

bool Rook::hasBeenMoved() {
	return hasBeenMoved;
}

char Rook::getPieceType() {
	return 'R';
}

vector<Move> Rook::getPossibleMoves() {
	vector<Move> PossibleMoves;
	int row = location.getRow();
	int col = location.getCol();

	row--; //Doesn't move onto it's own square
	while (row > -1) { // Find all the rows above that rook can move too
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
		row--;
	}
	row = location.getRow(); // Reset the row

	row++; //Doesn't move onto it's own square
	while (row < 8) { // Find all the rows below that rook can move too
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
		row++;
	}
	row = location.getRow(); // Reset the row

	col++; //Doesn't move onto it's own square
	while (col < 8) { // Find all the columns to the right that rook can move too
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
		col++;
	}
	col = location.getCol(); // Reset the col

	col--; //Doesn't move onto it's own square
	while (col > -1) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
		col++;		
	}
	return PossibleMoves;
}
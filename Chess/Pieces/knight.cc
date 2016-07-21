#include "knight.h"
#include "move.h"
#include "chesspiece.h"

char Knight::getPieceType() const {
	return 'N';
}

vector<Move> Knight::getPossibleMoves() const {
	vector<Move> PossibleMoves;
	int row = location.getRow();
	int col = location.getCol();

	// Up 2, Left 1
	row = row - 2;
	col--;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
	}
	row = location.getRow();
	col = location.getCol();

	// Up 2, Right 1
	row = row - 2;
	col++;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
	}
	row = location.getRow();
	col = location.getCol();


	// Right 2, Up 1
	row--;
	col = col + 2;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
	}
	row = location.getRow();
	col = location.getCol();


	// Right 2, Down 1
	row++;
	col = col + 2;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
	}
	row = location.getRow();
	col = location.getCol();


	// Down 2, Left 1
	row = row - 2;
	col--;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
	}
	row = location.getRow();
	col = location.getCol();

	// Down 2, Right 1
	row = row - 2;
	col++;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
	}
	row = location.getRow();
	col = location.getCol();

	// Left 2, Up 1
	row--;
	col = col + 2;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
	}
	row = location.getRow();
	col = location.getCol();

	// Left 2, Down 1
	row++;
	col = col + 2;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		PossibleMoves.emplace_back(Move(this, Posn(row, col)));
	}
	row = location.getRow();
	col = location.getCol();

	return PossibleMoves;
}
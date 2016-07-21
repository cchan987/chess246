#include "bishop.h"
#include "move.h"
#include "chesspiece.h"

char Bishop::getPieceType() {
	return 'B';
}

vector<Move> Bishop::getPossibleMoves() {
	vector<Move> PossibleMoves;
	int row = location.getRow();
	int col = location.getCol();

	while (true) { // check up right
		if (col == 8 || row == -1) {
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, Posn(row, col)));
		}
		col++;
		row--;
	}
	row = location.getRow();
	col = location.getCol();

	while (true) { // check up left
		if (col == -1 || row == -1) {
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, Posn(row, col)));
		}
		col--;
		row--;
	}
	row = location.getRow();
	col = location.getCol();

	while (true) { // check down right
		if (col == 8 || row == 8) {
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, Posn(row, col)));
		}
		col++;
		row++;
	}
	row = location.getRow();
	col = location.getCol();

	while (true) { // check down left
		if (col == -1 || row == 8) {
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, Posn(row, col)));
		}
		col--;
		row++;
	}
	row = location.getRow();
	col = location.getCol();

	return PossibleMoves;
}
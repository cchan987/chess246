#include "queen.h"
#include "move.h"
#include "chesspiece.h"

char Queen::getPieceType() const {
	return 'Q';
}

vector<Move> Queen::getPossibleMoves() const {
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
	col = location.getCol();


	//Next Check the diagaonals
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
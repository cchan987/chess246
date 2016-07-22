#include "queen.h"
#include "move.h"
#include "board.h"
#include "chesspiece.h"
using namespace std;

char Queen::getPieceType() {
	return 'Q';
}

vector<Move> Queen::getPossibleMoves(Board &B) {
	vector<Move> PossibleMoves;
	int row = location.getRow();
	int col = location.getCol();

	row--; //Doesn't move onto it's own square
	while (row > -1) { // Find all the rows above that rook can move too
		Posn currentPosn = Posn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
		row--;
	}
	row = location.getRow(); // Reset the row

	row++; //Doesn't move onto it's own square
	while (row < 8) { // Find all the rows below that rook can move too
		currentPosn = Posn(row, col);
		pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
		row++;
	}
	row = location.getRow(); // Reset the row

	col++; //Doesn't move onto it's own square
	while (col < 8) { // Find all the columns to the right that rook can move too
		currentPosn = Posn(row, col);
		pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
		col++;
	}
	col = location.getCol(); // Reset the col

	col--; //Doesn't move onto it's own square
	while (col > -1) {
		currentPosn = Posn(row, col);
		pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
		col--;		
	}
	col = location.getCol();


	//Next Check the diagaonals
	while (true) { // check up right
		col++;
		row--;
		if (col == 8 || row == -1) {
			break;
		}
		currentPosn = Posn(row, col);
		pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	row = location.getRow();
	col = location.getCol();

	while (true) { // check up left
		col--;
		row--;
		if (col == -1 || row == -1) {
			break;
		}
		currentPosn = Posn(row, col);
		pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	row = location.getRow();
	col = location.getCol();

	while (true) { // check down right
		col++;
		row++;
		if (col == 8 || row == 8) {
			break;
		}
		currentPosn = Posn(row, col);
		pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	row = location.getRow();
	col = location.getCol();

	while (true) { // check down left
		col--;
		row++;
		if (col == -1 || row == 8) {
			break;
		}
		currentPosn = Posn(row, col);
		pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	return PossibleMoves;
}
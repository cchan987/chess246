#include "bishop.h"
#include "move.h"
#include "chesspiece.h"
#include <vector>
#include "board.h"

using namespace std;

Bishop::Bishop(char c, Posn p):ChessPiece{c, p}{}

Bishop::~Bishop(){}

char Bishop::getPieceType() {
	return 'B';
}


vector<Move> Bishop::getPossibleMoves(Board &b) {
	vector<Move> PossibleMoves;
	int row = location.getRow();
	int col = location.getCol();

	col++;
	row--;
	while (true) { // check up right
		Posn currentPosn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (col == 8 || row == -1) {
			break;
		}
		if (pieceAtPosn) { //Ran into a piece
			if (!(pieceAtPosn->getColour() == colour)) { // ran into opponents piece
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		PossibleMoves.emplace_back(Move(this, currentPosn)); // No conflict
		col++;
		row--;
	}
	row = location.getRow();
	col = location.getCol();

	col--;
	row--;
	while (true) { // check up left
		Posn currentPosn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (col == -1 || row == -1) {
			break;
		}
		if (pieceAtPosn) { //Ran into a piece
			if (!(pieceAtPosn->getColour() == colour)) { // ran into opponents piece
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		PossibleMoves.emplace_back(Move(this, currentPosn)); // No conflict
		col--;
		row--;
	}
	row = location.getRow();
	col = location.getCol();

	col++;
	row++;
	while (true) { // check down right
		Posn currentPosn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (col == 8 || row == 8) {
			break;
		}
		if (pieceAtPosn) { //Ran into a piece
			if (!(pieceAtPosn->getColour() == colour)) { // ran into opponents piece
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		PossibleMoves.emplace_back(Move(this, currentPosn)); // No conflict
		col++;
		row++;
	}
	row = location.getRow();
	col = location.getCol();

	col--;
	row++;
	while (true) { // check down left
		Posn currentPosn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (col == -1 || row == 8) {
			break;
		}
		if (pieceAtPosn) { //Ran into a piece
			if (!(pieceAtPosn->getColour() == colour)) { // ran into opponents piece
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
			break;
		}
		PossibleMoves.emplace_back(Move(this, currentPosn)); // No conflict
		col--;
		row++;
	}
	row = location.getRow();
	col = location.getCol();

	return PossibleMoves;
}
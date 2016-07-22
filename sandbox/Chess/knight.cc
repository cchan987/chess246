#include "knight.h"
#include "move.h"
#include "chesspiece.h"
#include "board.h"

using namespace std;

Knight::Knight(char c, Posn p):ChessPiece{c, p} {}
Knight::~Knight(){}

char Knight::getPieceType() {
	return 'N';
}

vector<Move> Knight::getPossibleMoves(Board &b) {
	vector<Move> PossibleMoves;
	int row = location.getRow();
	int col = location.getCol();

	// Up 2, Left 1
	row = row - 2;
	col--;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		Posn currentPosn = Posn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn){
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}

	row = location.getRow();
	col = location.getCol();

	// Up 2, Right 1
	row = row - 2;
	col++;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		Posn currentPosn = Posn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn){
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	row = location.getRow();
	col = location.getCol();


	// Right 2, Up 1
	row--;
	col = col + 2;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		Posn currentPosn = Posn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn){
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	row = location.getRow();
	col = location.getCol();


	// Right 2, Down 1
	row++;
	col = col + 2;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		Posn currentPosn = Posn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn){
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	row = location.getRow();
	col = location.getCol();


	// Down 2, Left 1
	row = row - 2;
	col--;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		Posn currentPosn = Posn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn){
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	row = location.getRow();
	col = location.getCol();

	// Down 2, Right 1
	row = row - 2;
	col++;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		Posn currentPosn = Posn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn){
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	row = location.getRow();
	col = location.getCol();

	// Left 2, Up 1
	row--;
	col = col + 2;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		Posn currentPosn = Posn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn){
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	row = location.getRow();
	col = location.getCol();

	// Left 2, Down 1
	row++;
	col = col + 2;
	if (col > -1 && col < 8 && row < 8 && row > -1) {
		Posn currentPosn = Posn(row, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn){
			if (pieceAtPosn->getColour() != colour) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}
	row = location.getRow();
	col = location.getCol();

	return PossibleMoves;
}
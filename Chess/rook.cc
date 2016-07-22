#include "rook.h"
#include "board.h"
#include "move.h"
#include "chesspiece.h"

using namespace std;

Rook::Rook(char c, Posn p):ChessPiece{c, p} {}
Rook::~Rook(){}

void Rook::setMoved() {
	hasBeenMoved = true;
}

bool Rook::getHasBeenMoved() const {
	return hasBeenMoved;
}

char Rook::getPieceType() {
	return 'R';
}

void Rook::setPosition(Posn p){
	setMoved();
	location = p;
}

vector<Move> Rook::getPossibleMoves(Board &b) {
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
		row++;
	}
	row = location.getRow(); // Reset the row

	col++; //Doesn't move onto it's own square
	while (col < 8) { // Find all the columns to the right that rook can move too
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
		col++;
	}
	col = location.getCol(); // Reset the col

	col--; //Doesn't move onto it's own square
	while (col > -1) {
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
		col--;		
	}
	col = location.getCol();
	return PossibleMoves;
}
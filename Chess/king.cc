#include "king.h"
#include "move.h"
#include "board.h"
#include "chesspiece.h"

using namespace std;

King::King(char c, Posn p):ChessPiece{c, p}{}

King::~King(){}

void King::setMoved() {
	hasBeenMoved = true;
}

bool King::getHasBeenMoved() const {
	return hasBeenMoved;
}

char King::getPieceType() {
	return 'K';
}

void King::setPosition(Posn p){
	setMoved();
	location = p;
}


vector<Move> King::getPossibleMoves(Board &b) {
	vector<Move> PossibleMoves;


	int row = location.getRow();
	int col = location.getCol();

	if (row < 7) { // moving down
		Posn currentPosn = Posn(row + 1, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (!(pieceAtPosn->getColour() == colour)) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		} 
	}

	if (row > 0) { // moving up
		Posn currentPosn = Posn(row - 1, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (!(pieceAtPosn->getColour() == colour)) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		} 
	}

	if (col > 0) { // moving left
		Posn currentPosn = Posn(row, col - 1);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (!(pieceAtPosn->getColour() == colour)) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		} 
	}

	if (col < 7) { // moving right
		Posn currentPosn = Posn(row, col + 1);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn) {
			if (!(pieceAtPosn->getColour() == colour)) {
				PossibleMoves.emplace_back(Move(this, currentPosn, true));
			}
		}
		else {
			PossibleMoves.emplace_back(Move(this, currentPosn));
		}
	}

	if (hasBeenMoved == false) { // Can potentially castle
		//Check castling right
		ChessPiece *rightOne = b.getPieceByPosn(Posn(row, col + 1));
		ChessPiece* rightTwo = b.getPieceByPosn(Posn(row, col + 2));
		ChessPiece* rightThree = b.getPieceByPosn(Posn(row, col + 3));
		if (rightOne == nullptr && rightTwo == nullptr) { // No pieces in the way
			if (rightThree != nullptr) { //Piece in the rook square
				if (rightThree->getColour() == colour && rightThree->getPieceType() == 'R'){ // piece is friendly rook
					if (rightThree->getHasBeenMoved() == false) { // friendly rook hasn't moved
						PossibleMoves.emplace_back(Move(this, Posn(row, col + 2), false, true));
					}
				}
			}
		}
		//Check castling left
		ChessPiece *leftOne = b.getPieceByPosn(Posn(row, col - 1));
		ChessPiece *leftTwo = b.getPieceByPosn(Posn(row, col - 2));
		ChessPiece *leftThree = b.getPieceByPosn(Posn(row, col - 3));
		ChessPiece *leftFour = b.getPieceByPosn(Posn(row, col - 4));
		if (leftOne == nullptr && leftTwo == nullptr && leftThree == nullptr) {
			if (leftFour != nullptr) {
				if (leftFour->getColour() == colour && leftFour->getPieceType() == 'R') {
					if (leftFour->getHasBeenMoved() == false) {
						PossibleMoves.emplace_back(Move(this, Posn(row, col - 2), false, true));
					}
				}
			}
		}
	}
	
	return PossibleMoves;
}

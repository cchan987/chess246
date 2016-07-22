
#include "chesspiece.h"
#include "move.h"
#include "pawn.h"
#include "board.h"

using namespace std;

Pawn::Pawn(char c, Posn p):ChessPiece{c, p} {}
Pawn::~Pawn(){}

void Pawn::setMoved() {
	hasBeenMoved = true;
}

bool Pawn::getHasBeenMoved() const {
	return hasBeenMoved;
}

char Pawn::getPieceType() {
	return 'P';
}


vector<Move> Pawn::getPossibleMoves(Board &b) {
	vector<Move> PossibleMoves;
	int row = location.getRow();
	int col = location.getCol();	
	if (colour == 'W'){

		if (col - 1 > -1) { // capture diagonal left
			Posn currentPosn = Posn(row - 1, col - 1);
			ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
			if (pieceAtPosn) {
				if (pieceAtPosn->getColour() == 'B') {
					PossibleMoves.emplace_back(Move(this, currentPosn, true));
				}
			}
		}

		if (col + 1 < 8){ // Capture diagonal right
			Posn currentPosn = Posn(row - 1, col + 1);
			ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
			if (pieceAtPosn) {
				if (pieceAtPosn->getColour() == 'B') {
					PossibleMoves.emplace_back(Move(this, currentPosn, true));
				}
			}
		}

		// Moving up
		Posn currentPosn = Posn(row - 1, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn == nullptr) {
			PossibleMoves.emplace_back(Move(this, currentPosn));			
		}

		// Moving double fwd
		if (hasBeenMoved == false) {
			ChessPiece *oneFwd = b.getPieceByPosn(Posn(row - 1, col));
			ChessPiece *twoFwd = b.getPieceByPosn(Posn(row - 2, col));
			if (oneFwd == nullptr && twoFwd == nullptr){
				PossibleMoves.emplace_back(Move(this, Posn(row - 2, col)));			
			}
		}
/*
		if (row == 3) { // en passant possibility
			if (col > 0) { // we are not in the A column, therefore we check left for vulnerable pawn
				ChessPiece *pieceLeft = b.getPieceByPosn(Posn(row, col - 1));
				if (pieceLeft) {
					if (pieceLeft->enPassantPossible()) {
						PossibleMoves.emplace_back(Move(this, Posn(row - 1, col - 1)), false, false , true);
					}				
				}
			}
			if (col < 7) {
				ChessPiece *pieceRight = b.getPieceByPosn(Posn(row, col + 1));
				if (pieceRight) {
					if (pieceRight->enPassantPossible()) {
						PossibleMoves.emplace_back(Move(this, Posn(row - 1, col + 1)), false, false , true);
					}				
				}
			}
		}*/
	}

	if (colour == 'B'){
		if (col - 1 > -1) { // capture diagonal left
			Posn currentPosn = Posn(row + 1, col - 1);
			ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
			if (pieceAtPosn) {
				if (pieceAtPosn->getColour() == 'W') {
					PossibleMoves.emplace_back(Move(this, currentPosn, true));
				}
			}
		}

		if (col + 1 < 8){ // Capture diagonal right
			Posn currentPosn = Posn(row + 1, col + 1);
			ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
			if (pieceAtPosn) {
				if (pieceAtPosn->getColour() == 'W') {
					PossibleMoves.emplace_back(Move(this, currentPosn, true));
				}
			}
		}

		// Moving down
		Posn currentPosn = Posn(row + 1, col);
		ChessPiece *pieceAtPosn = b.getPieceByPosn(currentPosn);
		if (pieceAtPosn == nullptr) {
			PossibleMoves.emplace_back(Move(this, currentPosn));			
		}

		// Moving double fwd
		if (hasBeenMoved == false) {
			ChessPiece *oneFwd = b.getPieceByPosn(Posn(row + 1, col));
			ChessPiece *twoFwd = b.getPieceByPosn(Posn(row + 2, col));
			if (oneFwd == nullptr && twoFwd == nullptr){
				PossibleMoves.emplace_back(Move(this, Posn(row + 2, col)));			
			}
		}
/*
		if (row == 4) { // en passant possibility
			if (col > 0) { // we are not in the A column, therefore we check left for vulnerable pawn
				ChessPiece *pieceLeft = b.getPieceByPosn(Posn(row, col - 1));
				if (pieceLeft) {
					if (pieceLeft->enPassantPossible()) {
						PossibleMoves.emplace_back(Move(this, Posn(row + 1, col - 1)), false, false , true);
					}				
				}
			}
			if (col < 7) {
				ChessPiece *pieceRight = b.getPieceByPosn(Posn(row, col + 1));
				if (pieceRight) {
					if (pieceRight->enPassantPossible()) {
						PossibleMoves.emplace_back(Move(this, Posn(row + 1, col + 1)), false, false , true);
					}				
				}
			}
		}*/
	}
	
	return PossibleMoves;
}

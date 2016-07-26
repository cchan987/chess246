#include "move.h"
#include "chesspiece.h"
#include "posn.h"

Move::Move(ChessPiece *Piece, Posn dst, 
	bool isCapturingMove, bool isCastlingMove, bool isEnPassantCaptureMove): 
	Piece{Piece}, dst{dst}, isCapturingMove{isCapturingMove}, 
	isCastlingMove{isCastlingMove}, isEnPassantCaptureMove{isEnPassantCaptureMove} {}

ChessPiece * Move::getPiece() const{
	return Piece;
}
Posn Move::getDestination() const{
	return dst;
}

bool Move::getIsCapturingMove() const {
	return isCapturingMove;
}

bool Move::getIsCastlingMove() const {
	return isCastlingMove;
}

bool Move::getIsEnPassantCaptureMove() const {
	return isEnPassantCaptureMove;
}
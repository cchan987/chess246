#include "move.h"
#include "chesspiece.h"
#include "posn.h"

Move::Move(ChessPiece *Piece, Posn dst, bool isCapturingMove = false, bool isCastlingMove = false, bool isEnPassantCaptureMove = false) : Piece{Piece}, dst{dst}, isCapturingMove{isCapturingMove}, isCastlingMove{isCastlingMove}, isEnPassantCaptureMove{isEnPassantCaptureMove} {}

ChessPiece *Move::getPiece() {
	return Piece;
}
Posn Move::getDestination() {
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
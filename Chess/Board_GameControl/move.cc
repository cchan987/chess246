#include "move.h"
#include "chesspiece.h"
#include "posn.h"

Move::Move(ChessPiece *Piece, Posn dst, bool isCapturingMove, bool isCastlingMove); : Piece{Piece}, dst{dst}, isCapturingMove{isCapturingMove}, isCastlingMove{isCastlingMove} {}

ChessPiece *Move::getPiece() {
	return Piece;
}
Posn Move::getDestination() {
	return dst;
}
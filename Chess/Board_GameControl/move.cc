#include "move.h"
#include "chesspiece.h"
#include "posn.h"

Move::Move(ChessPiece *p, Posn d, bool i) : Piece{p}, dst{d}, isCapturingMove{i} {}

ChessPiece *Move::getPiece() {
	return Piece;
}
Posn Move::getDestination() {
	return dst;
}
#include "move.h"
#include "chesspiece.h"
#include "posn.h"


ChessPiece *Move::getPiece() {
	return Piece;
}
Posn Move::getDestination() {
	return dst;
}
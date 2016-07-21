#include "move.h"
#include "chesspiece.h"
#include "posn.h"

Move::Move(ChessPiece *Piece, Posn dst, bool isCapturingMove = false, bool isCastlingMove = false, bool isEnPassantMove = false); : Piece{Piece}, dst{dst}, isCapturingMove{isCapturingMove}, isCastlingMove{isCastlingMove}, isEnPassantMove{isEnPassantMove} {}

ChessPiece *Move::getPiece() {
	return Piece;
}
Posn Move::getDestination() {
	return dst;
}
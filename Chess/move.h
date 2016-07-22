#ifndef __MOVE_H__
#define __MOVE_H__
#include "posn.h"

class ChessPiece;

class Move{
	ChessPiece *Piece;
	Posn dst;
	bool isCapturingMove;
	bool isCastlingMove;
	bool isEnPassantCaptureMove;
public:
	Move(ChessPiece *Piece, Posn dst, bool isCapturingMove = false, bool isCastlingMove = false, bool isEnPassantCaptureMove = false);
	ChessPiece * getPiece() const;
	Posn getDestination() const;
	bool getIsCapturingMove() const;
	bool getIsCastlingMove() const;
	bool getIsEnPassantCaptureMove() const;
};

#endif
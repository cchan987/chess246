#ifndef __MOVE_H__
#define __MOVE_H__

class ChessPiece;
class Posn;

class Move{
	ChessPiece *Piece;
	Posn dst;
	bool isCapturingMove;
	bool isCastlingMove;
public:
	Move(ChessPiece *Piece, Posn dst, bool isCapturingMove = false, bool isCastlingMove = false);
	ChessPiece *getPiece() const;
	Posn getDestination() const;
};

#endif
#ifndef __MOVE_H__
#define __MOVE_H__

class ChessPiece;
class Posn;

class Move{
	ChessPiece *Piece;
	Posn dst;
	bool isCapturingMove;
public:
	Move(ChessPiece *p, Posn d, bool i);
	ChessPiece *getPiece() const;
	Posn getDestination() const;
};

#endif
#ifndef __MOVE_H__
#define __MOVE_H__

class ChessPiece;
class Posn;

class Move{
	ChessPiece *Piece;
	Posn dst;
public:
	ChessPiece *getPiece();
	Posn getDestination();
};

#endif
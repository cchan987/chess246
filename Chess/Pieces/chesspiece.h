#ifndef ROOK_H
#define ROOK_H

#include "posn.h"
#include "move.h"

class ChessPiece {
	char colour;
	Posn location;
public:
	ChessPiece(char c, Posn p);
	char getColour();
	void setColour(char col);
	Posn getPosition();
	void setPosition(Posn p);
	virtual vector<Move> getPossibleMoves() = 0;
	virtual char getPieceType() = 0;
};
#endif
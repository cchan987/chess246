#ifndef ROOK_H
#define ROOK_H

#include "posn.h"
#include "move.h"

class ChessPiece {
	char colour;
	Posn location;
public:
	ChessPiece(char c, Posn p);
	char getColour() const;
	void setColour(char col);
	Posn getPosition() const;
	virtual void setPosition(Posn p);
	virtual vector<Move> getPossibleMoves() const = 0;
	virtual char getPieceType() const = 0;
};
#endif
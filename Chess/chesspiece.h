#ifndef ROOK_H
#define ROOK_H

#include "posn.h"
#include "move.h"
#include <vector>
class Board;

class ChessPiece {
protected:
	char colour;
	Posn location;
public:
	ChessPiece(char c, Posn p);
	char getColour();
	void setColour(char col);
	Posn getPosition();
	virtual void setPosition(Posn p);
	virtual std::vector<Move> getPossibleMoves(Board &b) = 0;
	virtual char getPieceType() = 0;
};
#endif
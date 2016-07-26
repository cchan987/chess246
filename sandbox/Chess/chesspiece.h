#ifndef CHESSPIECE_H
#define CHESSPIECE_H

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
	virtual ~ChessPiece();
	char getColour() const;
	void setColour(char col);
	Posn getPosition() const;
	virtual bool getHasBeenMoved() const;
	virtual void setPosition(Posn p);
	virtual std::vector<Move> getPossibleMoves(Board &b) = 0;
	virtual char getPieceType() = 0;

	virtual bool enPassantPossible() const;
	virtual void setEnPassantFlag(bool value);
	virtual void setMoved();
};
#endif
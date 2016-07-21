#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class Move;
class Posn;

class King :public ChessPiece {
	bool hasBeenMoved = false;
public:
	void setMoved();
	bool getHasBeenMoved() const;
	char getPieceType() const override;
	vector<Move> getPossibleMoves() const override;
	void setPosition(Posn p) override;
};

#endif
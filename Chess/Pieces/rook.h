#ifndef ROOK_H
#define ROOK_H
#include "chesspiece.h"

class Move;
class Posn;

class Rook :public ChessPiece {
	bool hasBeenMoved = false;
public:
	void setMoved();
	bool getHasBeenMoved() const;
	char getPieceType() const override;
	vector<Move> getPossibleMoves() const override;
	void setPosition(Posn p) override;
};

#endif
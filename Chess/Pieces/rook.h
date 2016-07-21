#ifndef ROOK_H
#define ROOK_H
#include "chesspiece.h"

class Move;

class Rook :public ChessPiece {
	bool hasBeenMoved = false;
public:
	void setMoved();
	bool getHasBeenMoved();
	char getPieceType() override;
	vector<Move> getPossibleMoves() override;
	void setPosition(Posn p) override;
};

#endif
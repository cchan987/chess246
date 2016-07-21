#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class Move;

class King :public ChessPiece {
	bool hasBeenMoved = false;
public:
	void setMoved();
	bool getHasBeenMoved();
	char getPieceType() override;
	vector<Move> getPossibleMoves() override;
};

#endif
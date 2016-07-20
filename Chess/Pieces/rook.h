#ifndef ROOK_H
#define ROOK_H
#include "chesspiece.h"

class Move;

class rook :public ChessPiece {
	bool hasBeenMoved = false;
public:
	void setMoved();
	bool getHasBeenMoved();
	char getPieceType() override;
	vector<Move> getPossibleMoves() override;
};

#endif
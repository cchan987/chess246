#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Move;

class Knight :public ChessPiece {
public:
	char getPieceType() const override;
	vector<Move> getPossibleMoves() const override;
};

#endif
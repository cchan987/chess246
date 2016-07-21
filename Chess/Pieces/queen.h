#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"

class Move;

class Queen :public ChessPiece {
public:
	char getPieceType() const override;
	vector<Move> getPossibleMoves() const override;
};

#endif
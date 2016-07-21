#ifndef BISHOP_H
#define BISHOP_H
#include "chesspiece.h"

class Move;

class Bishop :public ChessPiece {
public:
	char getPieceType() const override;
	vector<Move> getPossibleMoves() const override;
};

#endif
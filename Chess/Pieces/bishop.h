#ifndef BISHOP_H
#define BISHOP_H
#include "chesspiece.h"

class Move;

class Bishop :public ChessPiece {
public:
	char getPieceType() override;
	vector<Move> getPossibleMoves() override;
};

#endif
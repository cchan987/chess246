#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Move;

class Knight :public ChessPiece {
public:
	char getPieceType() override;
	vector<Move> getPossibleMoves() override;
};

#endif
#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"

class Move;

class Queen :public ChessPiece {
public:
	char getPieceType() override;
	vector<Move> getPossibleMoves() override;
};

#endif
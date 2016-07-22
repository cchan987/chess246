#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Move;
class Board;

class Knight :public ChessPiece {
public:
	char getPieceType() override;
	std::vector<Move> getPossibleMoves(Board &b) override;
};

#endif
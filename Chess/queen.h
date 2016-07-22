#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"

class Move;
class Board;

class Queen :public ChessPiece {
public:
	char getPieceType() override;
	std::vector<Move> getPossibleMoves(Board &b) override;
};

#endif
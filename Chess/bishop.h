#ifndef BISHOP_H
#define BISHOP_H
#include "chesspiece.h"

class Board;
class Move;

class Bishop :public ChessPiece {
public:
	char getPieceType() override;
	std::vector<Move> getPossibleMoves(Board &b) override;
};

#endif
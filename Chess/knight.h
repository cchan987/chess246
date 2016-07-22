#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Move;
class Board;

class Knight :public ChessPiece {
public:
	Knight(char c, Posn p);
	~Knight();
	char getPieceType() override;
	std::vector<Move> getPossibleMoves(Board &b) override;
};

#endif
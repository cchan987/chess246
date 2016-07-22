#ifndef ROOK_H
#define ROOK_H
#include "chesspiece.h"

class Move;
class Posn;
class Board;

class Rook :public ChessPiece {
	bool hasBeenMoved = false;
public:
	void setMoved();
	bool getHasBeenMoved() const;
	char getPieceType() override;
	std::vector<Move> getPossibleMoves(Board &b) override;
	void setPosition(Posn p) override;
};

#endif
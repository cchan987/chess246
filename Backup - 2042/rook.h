#ifndef ROOK_H
#define ROOK_H
#include "chesspiece.h"

class Move;
class Posn;
class Board;

class Rook: public ChessPiece {
	bool hasBeenMoved = false;
public:
	Rook(char c, Posn p);
	~Rook();
	void setMoved() override;
	bool getHasBeenMoved() const override;
	char getPieceType() override;
	std::vector<Move> getPossibleMoves(Board &b) override;
	void setPosition(Posn p) override;
};

#endif
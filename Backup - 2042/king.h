#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class Move;
class Posn;
class Board;

class King :public ChessPiece {
	bool hasBeenMoved = false;
public:
	King(char c, Posn p);
	~King();
	void setMoved() override;
	bool getHasBeenMoved() const override;
	char getPieceType() override;
	std::vector<Move> getPossibleMoves(Board &b) override;
	void setPosition(Posn p) override;
};

#endif
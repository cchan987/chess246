#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"
class Move;
class Posn;
class Board;

class Pawn:public ChessPiece{
	bool hasBeenMoved = false;
public:
	void setMoved();
	bool getHasBeenMoved() const;
	char getPieceType() override;
	std::vector<Move> getPossibleMoves(Board &b) override;

};

#endif

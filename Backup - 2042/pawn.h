#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"
class Move;
class Posn;
class Board;

class Pawn:public ChessPiece{
	bool hasBeenMoved = false;
	bool canBeCapturedEnPassant = false;
public:
	Pawn(char c, Posn p);
	~Pawn();
	void setMoved() override;
	bool getHasBeenMoved() const override;
	char getPieceType() override;
	std::vector<Move> getPossibleMoves(Board &b) override;

	bool enPassantPossible() const override;
	void setEnPassantFlag(bool value) override;
};

#endif

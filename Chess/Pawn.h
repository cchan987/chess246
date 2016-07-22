#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"
class Move;
class Posn;

class Pawn:public ChessPiece{
	bool hasBeenMoved = false;
public:
	void setMoved();
	bool getHasBeenMoved();
	char getPieceType() override;	
	vector<Move> getPossibleMoves(Posn p) override;

};

#endif

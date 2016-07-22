#ifndef PAWN_H
#define PAWN_H

#include <ChessPiece.h>
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

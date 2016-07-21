#ifndef PAWN_H
#define PAWN_H

#include <ChessPiece.h>
class Move;
class Posn;

class Pawn:public ChessPiece{
	bool hasBeenMoved = false;
public:
	void setMoved();
	bool getHasBeenMoved() const;
	char getPieceType() const override;	
	vector<Move> getPossibleMoves(Posn p) const override;

};

#endif

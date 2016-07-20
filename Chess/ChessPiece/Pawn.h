#ifndef _PAWN_H_
#define _PAWN_H_
#include <string>

class Pawn : public ChessPiece {
public:
	Pawn(char colour, bool hasBeenMoved, Posn *location);
	std::string getPieceType() const override;
};

#endif
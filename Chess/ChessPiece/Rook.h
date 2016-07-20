#ifndef _ROOK_H_
#define _ROOK_H_
#include <string>

class Rook : public ChessPiece {
public:
	Rook(char colour, bool hasBeenMoved, Posn *location);
	std::string getPieceType() const override;
};

#endif
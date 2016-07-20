#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include <string>

class Knight : public ChessPiece {
public:
	Knight(char colour, bool hasBeenMoved, Posn *location);
	std::string getPieceType() const override;
};

#endif
#ifndef _BISHOP_H_
#define _BISHOP_H_
#include <string>

class Bishop : public ChessPiece {
public:
	Bishop(char colour, bool hasBeenMoved, Posn *location);
	std::string getPieceType() const override;
};

#endif
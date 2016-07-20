#ifndef _QUEEN_H_
#define _QUEEN_H_
#include <string>

class Queen : public ChessPiece {
public:
	Queen(char colour, bool hasBeenMoved, Posn *location);
	std::string getPieceType() const override;
};

#endif
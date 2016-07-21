#ifndef _ROOK_H_
#define _ROOK_H_
#include <string>
#include <vector>

class Rook : public ChessPiece {
public:
	Rook(char colour, bool hasBeenMoved, Posn *location);
	std::string getPieceType() const override;
	std::vector<Posn *> getPossibleMoves() const override;
};

#endif
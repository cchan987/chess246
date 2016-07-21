#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include <string>
#include <vector>

class Knight : public ChessPiece {
public:
	Knight(char colour, bool hasBeenMoved, Posn *location);
	std::string getPieceType() const override;
	std::vector<Posn *> getPossibleMoves() const override;
};

#endif
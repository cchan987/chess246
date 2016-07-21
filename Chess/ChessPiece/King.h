#ifndef _KING_H_
#define _KING_H_
#include <string>
#include <vector>

class King : public ChessPiece {
public:
	King(char colour, bool hasBeenMoved, Posn *location);
	std::string getPieceType() const override;
	std::vector<Posn *> getPossibleMoves() const override;
};

#endif
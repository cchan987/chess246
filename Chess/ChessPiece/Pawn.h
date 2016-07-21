#ifndef _PAWN_H_
#define _PAWN_H_
#include <string>
#include <vector>

class Pawn : public ChessPiece {
	bool isFirstMove;
public:
	Pawn(char colour, bool hasBeenMoved, Posn *location, bool isFirstMove);
	bool isitFirstMove() const;
	void pawnHasMoved();
	std::vector<Posn *> getPossibleCaptures() const;

	std::string getPieceType() const override;
	std::vector<Posn *> getPossibleMoves() const override;
};

#endif
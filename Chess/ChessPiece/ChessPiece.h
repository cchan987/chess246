#ifndef _CHESSPIECE_H_
#define _CHESSPIECE_H_

#include <string>
#include <vector>

class ChessPiece {
	char colour;
	bool hasBeenMoved;
	Posn *location;
public:
	ChessPiece(char colour, bool hasBeenMoved, Posn *location);
	char getColour() const;
	void setPosition(Posn *p);
	virtual std::string getPieceType() const = 0;
	virtual std::vector<Posn *> getPossibleMoves() const = 0;
	~ChessPiece();
};

#endif
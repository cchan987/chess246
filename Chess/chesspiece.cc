#include "chesspiece.h"

ChessPiece::ChessPiece(char c, Posn p) : colour{c}, location{p} {}

void ChessPiece::setColour(char col) {
	colour = col;
}

char ChessPiece::getColour() const {
	return colour;
}

Posn ChessPiece::getPosition() const {
	return location;
}

void ChessPiece::setPosition(Posn p) {
	location = p;
}
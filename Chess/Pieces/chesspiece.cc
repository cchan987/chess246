#include "chesspiece.h"

ChessPiece::ChessPiece(char c, Posn p) : colour{c}, location{p} {}

void ChessPiece::setColour(char col) {
	colour = col;
}

char ChessPiece::getColour() const {
	return colour;
}

Posn getPosition() const {
	return location;
}

void setPosition(Posn p) {
	location = p;
}
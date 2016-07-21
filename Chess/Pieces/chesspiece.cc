#include "chesspiece.h"

ChessPiece::ChessPiece(char c, Posn p) : colour{c}, location{p} {}

void ChessPiece::setColour(char col) {
	colour = col;
}

char ChessPiece::getColour() {
	return colour;
}

Posn getPosition() {
	return location;
}

void setPosition(Posn p) {
	location = p;
}
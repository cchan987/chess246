#include "ChessPiece.h"

ChessPiece::ChessPiece(char colour, bool hasBeenMoved, Posn *location) : colour{colour}, hasBeenMoved{hasBeenMoved} location{location} {}

char ChessPiece::getColour() const {
	return colour;
}

void ChessPiece::setPosition(Posn *p) {
	delete location;
	location = p;
}

ChessPiece::~ChessPiece() {
	delete location;
}
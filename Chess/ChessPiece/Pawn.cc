#include "Pawn.h"
#include <string>
using namespace std;

Pawn::Pawn(char colour, bool hasBeenMoved, Posn *location) : ChessPiece{colour, hasBeenMoved, location} {}

string Pawn::getPieceType() const {
	string n = "Pawn";
	return n
}
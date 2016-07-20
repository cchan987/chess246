#include "Rook.h"
#include <string>
using namespace std;

Rook::Rook(char colour, bool hasBeenMoved, Posn *location) : ChessPiece{colour, hasBeenMoved, location} {}

string Rook::getPieceType() const {
	string n = "Rook";
	return n
}
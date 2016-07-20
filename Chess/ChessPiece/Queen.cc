#include "Queen.h"
#include <string>
using namespace std;

Queen::Queen(char colour, bool hasBeenMoved, Posn *location) : ChessPiece{colour, hasBeenMoved, location} {}

string Queen::getPieceType() const {
	string n = "Queen";
	return n
}
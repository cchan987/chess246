#include "Knight.h"
#include <string>
using namespace std;

Knight::Knight(char colour, bool hasBeenMoved, Posn *location) : ChessPiece{colour, hasBeenMoved, location} {}

string Knight::getPieceType() const {
	string n = "Knight";
	return n
}
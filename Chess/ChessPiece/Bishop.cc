#include "Bishop.h"
#include <string>
using namespace std;

Bishop::Bishop(char colour, bool hasBeenMoved, Posn *location) : ChessPiece{colour, hasBeenMoved, location} {}

string Bishop::getPieceType() const {
	string n = "Bishop";
	return n
}
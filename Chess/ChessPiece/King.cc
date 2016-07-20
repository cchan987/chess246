#include "King.h"
#include <string>
using namespace std;

King::King(char colour, bool hasBeenMoved, Posn *location) : ChessPiece{colour, hasBeenMoved, location} {}

string King::getPieceType() const {
	string n = "King";
	return n
}

vector<Posn *> King::getPossibleMoves() const override {
	vector<Posn *> moves;
	currentRow = location->getRow();
	currentColumn = location->getColumn();

	if (currentRow + 1 <= 8) {
		Posn *up = new Posn(currentColumn, currentRow + 1);
		moves.push_back(up);
	}

	if (currentRow - 1 >= 1) {
		Posn *down = new Posn(currentColumn, currentRow + 1);
		moves.push_back(down);
	}

	if (currentColumn + 1 <= 8) {
		Posn *right = new Posn(currentColumn + 1, currentRow);
		moves.push_back(right);
	}

	if (location->getColumn() - 1 >= 0) {
		Posn *left = new Posn(currentColumn - 1, currentRow);
		moves.push_back(left);
	}
	return moves;
}
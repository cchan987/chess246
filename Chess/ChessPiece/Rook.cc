#include "Rook.h"
#include <string>
#include <vector>
using namespace std;

Rook::Rook(char colour, bool hasBeenMoved, Posn *location) : ChessPiece{colour, hasBeenMoved, location} {}

string Rook::getPieceType() const {
	string n = "Rook";
	return n
}

vector<Posn *> Rook::getPossibleMoves() const override {
	vector<Posn *> moves;
	currentRow = location->getRow();
	currentColumn = location->getColumn();

	for (int i = 1; i <= 8; ++i) {
		if (i != currentRow) {
			Posn *p = new Posn(currentColumn, i);
			moves.push_back(p);
		}

		if (i != currentColumn) {
			Posn *p = new Posn(i, currentRow);
			moves.push_back(p);
		}
	}

	return moves;
}
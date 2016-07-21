#include "Queen.h"
#include <string>
#include <vector>
using namespace std;

Queen::Queen(char colour, bool hasBeenMoved, Posn *location) : ChessPiece{colour, hasBeenMoved, location} {}

string Queen::getPieceType() const {
	string n = "Queen";
	return n
}

vector<Posn *> Queen::getPossibleMoves() const override {
	vector<Posn *> moves;
	currentRow = location->getRow();
	currentColumn = location->getColumn();

	// Search up-right
	for (int col = currentColumn, row = currentRow; col <= 8 && row <= 8; ++col, ++row) {
		Posn *p = new Posn(col, row);
		moves.push_back(p);
	}

	// Search down-left
	for (int col = currentColumn, row = currentRow; col >= 1 && row >= 1; --col, --row) {
		Posn *p = new Posn(col, row);
		moves.push_back(p);
	}

	// Search up-left
	for (int col = currentColumn, row = currentRow; col >= 1 && row <= 8; --col, ++row) {
		Posn *p = new Posn(col, row);
		moves.push_back(p);
	}

	// Search down-right
	for (int col = currentColumn, row = currentRow; col <= 8 && row >= 1; ++col, --row) {
		Posn *p = new Posn(col, row);
		moves.push_back(p);
	}

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
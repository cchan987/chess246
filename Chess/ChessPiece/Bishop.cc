#include "Bishop.h"
#include <string>
#include <vector>
using namespace std;

Bishop::Bishop(char colour, bool hasBeenMoved, Posn *location) : ChessPiece{colour, hasBeenMoved, location} {}

string Bishop::getPieceType() const {
	string n = "Bishop";
	return n
}

vector<Posn *> Bishop::getPossibleMoves() const override {
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

	return moves;
}
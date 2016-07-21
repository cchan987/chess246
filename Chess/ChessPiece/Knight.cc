#include "Knight.h"
#include <string>
#include <vector>
using namespace std;

Knight::Knight(char colour, bool hasBeenMoved, Posn *location) : ChessPiece{colour, hasBeenMoved, location} {}

string Knight::getPieceType() const {
	string n = "Knight";
	return n
}

vector<Posn *> Knight::getPossibleMoves() const override {
	vector<Posn *> moves;
	currentRow = location->getRow();
	currentColumn = location->getColumn();

	if (currentRow + 2 <= 8) {
		if (currentColumn + 1 <= 8) {
			Posn *p = new Posn(currentColumn + 1, currentRow + 2);
			moves.push_back(p);
		}

		if (currentColumn - 1 >= 1) {
			Posn *p = new Posn(currentColumn - 1, currentRow + 2);
			moves.push_back(p);
		}
	}

	if (currentRow - 2 <= 1) {
		if (currentColumn + 1 <= 8) {
			Posn *p = new Posn(currentColumn + 1, currentRow - 2);
			moves.push_back(p);
		}

		if (currentColumn - 1 >= 1) {
			Posn *p = new Posn(currentColumn - 1, currentRow - 2);
			moves.push_back(p);
		}
	}

	if (currentColumn + 2 <= 8) {
		if (currentRow + 1 <= 8) {
			Posn *p = new Posn(currentColumn + 2, currentRow + 1);
			moves.push_back(p);
		}

		if (currentRow - 1 <= 1) {
			Posn *p = new Posn(currentColumn + 2, currentRow - 1);
			moves.push_back(p);
		}
	}

	if (currentColumn - 2 >= 1) {
		if (currentRow + 1 <= 8) {
			Posn *p = new Posn(currentColumn - 2, currentRow + 1);
			moves.push_back(p);
		}

		if (currentRow - 1 <= 1) {
			Posn *p = new Posn(currentColumn - 2, currentRow - 1);
			moves.push_back(p);
		}
	}

	return moves;
}
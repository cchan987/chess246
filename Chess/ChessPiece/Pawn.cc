#include "Pawn.h"
#include <string>
#include <vector>
using namespace std;

Pawn::Pawn(char colour, bool hasBeenMoved, Posn *location, bool isFirstMove) : ChessPiece{colour, hasBeenMoved, location}, isFirstMove{isFirstMove} {}

string Pawn::getPieceType() const {
	string n = "Pawn";
	return n
}

bool Pawn::isitFirstMove() const {
	return isFirstMove;
}

void Pawn::pawnHasMoved() {
	isFirstMove = false;
}

vector<Posn *> Pawn::getPossibleCaptures() const {
	vector<Posn *> captures;
	currentRow = location->getRow();
	currentColumn = location->getColumn();

	Posn *p = new Posn(currentColumn + 1, currentRow + 1);
	moves.push_back(p);

	Posn *p = new Posn(currentColumn - 1, currentRow + 1);
	moves.push_back(p);

	return captures;
}

vector<Posn *> Pawn::getPossibleMoves() const override {
	vector<Posn *> moves;
	currentRow = location->getRow();
	currentColumn = location->getColumn();

	if (isFirstMove) {
		Posn *p = new Posn(currentColumn, currentRow + 2);
		moves.push_back(p);
	}

	Posn *p = new Posn(currentColumn, currentRow + 1);
	moves.push_back(p);

	return moves;
}
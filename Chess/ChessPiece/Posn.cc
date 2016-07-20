#include "Posn.h"

Posn::Posn(int column, int row) : column{column}, row{row} {}

int Posn::getColumn() {
	return column;
}

int Posn::getRow() {
	return row;
}
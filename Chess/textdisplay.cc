#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "posn.h"
#include "chesspiece.h"
using namespace std;

TextDisplay::TextDisplay() {

}

void TextDisplay::setDimensions(int n) {
	gridSize = n;
	for (int i = 0; i < n; i++) {
		vector<char> v;
		for (int j = 0; j < n; j++) {
			char colour = getCellColour(i, j);
			v.emplace_back(colour);
		}
		theDisplay.emplace_back(v);
	}	
}

void TextDisplay::notifyBoard(ChessPiece *cp, Posn dst) {
	if (cp) { // passed an actual piece
		int srcR = cp->getPosition().getRow();
		int srcC = cp->getPosition().getCol();
		char piece = cp->getPieceType();
		if (cp->getColour() == 'W') {
			piece = tolower(piece);
		}
		theDisplay[srcR][srcC] = piece;		
	}
	else { // passed a nullptr
		int dstR = dst.getRow();
		int dstC = dst.getCol();
		theDisplay[dstR][dstC] = getCellColour(dstR, dstC);		
	}
}

void TextDisplay::notifyInfoMsg(string msg) {
	infoMsg = msg;
}

TextDisplay::~TextDisplay() {}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (auto v: td.theDisplay) {
		for (auto c: v) {
			cout << c;
		}
		cout << endl;
	}
	cout << td.infoMsg << endl;
	return out;
}

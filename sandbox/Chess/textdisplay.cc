#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "posn.h"
#include "chesspiece.h"
#include "observer.h"
using namespace std;

TextDisplay::TextDisplay() {

}

void TextDisplay::setDimensions(int n) {
	gridSize = n;
	for (int i = 0; i < n; i++) {
		vector<char> v;
		for (int j = 0; j < n; j++) {
			char colour = getCellColour(i, j) == 'W' ? ' ' : '_';
			v.emplace_back(colour);
		}
		theDisplay.emplace_back(v);
	}	
}

void TextDisplay::notifyBoard(ChessPiece *cp, Posn dst) {
	if (cp) { // passed an actual piece
		int dstR = dst.getRow();
		int dstC = dst.getCol();
		char piece = cp->getPieceType();
		if (cp->getColour() == 'B') {
			piece = tolower(piece);
		}
		theDisplay[dstR][dstC] = piece;		
	}
	else { // passed a nullptr
		int dstR = dst.getRow();
		int dstC = dst.getCol();
		theDisplay[dstR][dstC] = getCellColour(dstR, dstC) == 'W' ? ' ' : '_';		
	}
}

void TextDisplay::notifyInfoMsg(string msg) {
	infoMsg = msg;
}

TextDisplay::~TextDisplay() {}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (unsigned int i = 0; i < td.theDisplay.size(); i++) {
		cout << i + 1 << ' ';
		for (unsigned int j = 0; j <td.theDisplay[i].size(); ++j) {
			cout << td.theDisplay[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "  abcdefgh" << endl;
	cout << td.infoMsg << endl;
	return out;
}

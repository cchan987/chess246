#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "cell.h"
using namespace std;

TextDisplay::TextDisplay(int n = 8): gridSize{n} {
	for (int i = 0; i < n; i++) {
		vector<char> v;
		for (int j = 0; j < n; j++) {
			char colour = getCellColour(i, j);
			v.emplace_back(colour);
		}
		theDisplay.emplace_back(v);
	}
}

void TextDisplay::notifyBoard(ChessPiece &cp, Posn src, Posn dst) {
	int srcR = src.getRow();
	int srcC = src.getCol();
	theDisplay[srcR][srcC] = getCellColour(srcR, srcC);

	int dstR = dst.getRow();
	int dstC = dst.getCol();
	theDisplay[srcR][srcC] = cp.getPieceType();
}

void notifyInfoMsg(String msg) {
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
	cout << infoMsg << endl;
	return out;
}

#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "cell.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n} {
	for (int i = 0; i < n; i++) {
		vector<char> v;
		for (int j = 0; j < n; j++) {
			v.emplace_back('_');
		}
		theDisplay.emplace_back(v);
	}
}

void TextDisplay::notify(Cell &c) {
	int r = c.getRow();
	int col = c.getCol();
	if (theDisplay[r][col] == '_') {
		theDisplay[r][col] = 'X';
	}
	else {
		theDisplay[r][col] = '_';
	}
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (auto v: td.theDisplay) {
		for (auto c: v) {
			cout << c;
		}
		cout << endl;
	}
	return out;
}

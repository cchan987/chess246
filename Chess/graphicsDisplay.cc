#include "window.h"
#include "graphicsDisplay.h"

using namespace std;

void GraphicsDisplay::notifyBoard(ChessPiece &cp, Posn src, Posn dst) {
	drawColourSqr(src.getRow(), src.getCol());
	drawColourSqr(dst.getRow(), dst.getCol());
	drawPiece(cp);
}

void GraphicsDisplay::notifyInfoMsg(String msg) {
	clearInfoBox();
	screen->drawString(stringXcord, stringYcord, msg);
}

void GraphicsDisplay::clearInfoBox() {
	screen->fillRectangle(stringXcord, stringYcord, 100, 20, Xwindow::Blue);
}

void GraphicsDisplay::drawPiece(ChessPiece &cp) {

}

void GraphicsDisplay::drawColourSqr(int r, int c) {
	char colour = getCellColor(r, c);
	if (colour == 'B') {
		screen->fillRectangle(leftPad + cellSize * i + i , topPad + j * cellSize + j, cellSize, cellSize, Xwindow::Black);	
	}
	else {
		screen->fillRectangle(leftPad + cellSize * i + i , topPad + j * cellSize + j, cellSize, cellSize, Xwindow::White);		
	}
}

GraphicsDisplay::GraphicsDisplay(Xwindow &w) {
	screen = &w;
	screen->fillRectangle(0,0,500,500, Xwindow::Blue);
}

GraphicsDisplay::~GraphicsDisplay(){}

void GraphicsDisplay::clearScreen() {
	screen->fillRectangle(0,0,500,500, Xwindow::Blue);
}

void GraphicsDisplay::setDimensions(int dim) {
	dimension = dim;
	cellSize = width / dimension;

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			drawColourSqr(i, j);
		}
	}
}

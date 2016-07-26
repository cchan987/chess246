#include "window.h"
#include "graphicsdisplay.h"
#include "posn.h"
#include "chesspiece.h"

using namespace std;

void GraphicsDisplay::notifyBoard(ChessPiece *cp, Posn dst) {
	Posn src = cp->getPosition();
	drawColourSqr(src.getRow(), src.getCol());
	drawColourSqr(dst.getRow(), dst.getCol());
	drawPiece(cp, dst);
}

void GraphicsDisplay::notifyInfoMsg(String msg) {
	clearInfoBox();
	screen->drawString(stringXcord, stringYcord, msg);
}

void GraphicsDisplay::clearInfoBox() {
	screen->fillRectangle(stringXcord, stringYcord, 100, 20, Xwindow::Blue);
}

void GraphicsDisplay::drawPiece(ChessPiece &cp, Posn location) {
	char cpType = cp.getPieceType();
	char cpColour = cp.getColour();

	// gets the centre of the cell that you want to draw in
	int xCord = leftpad + location.getCol() * cellSize + cellSize/2;
	int yCord = topPad + location.getRow() * cellSize + cellSize/2;

	if (cpColour == 'B') {
		if (cpType == 'R'){
			screen->fillRectangle(xCord , yCord, cellSize/ 1.5, cellSize / 2, Xwindow::Red);
		}
		if (cpType == 'N'){
			screen->fillRectangle(xCord , yCord, cellSize / 2, cellSize / 2, Xwindow::Red);
		}
		if (cpType == 'B'){
			screen->fillRectangle(xCord , yCord, cellSize / 2.5, cellSize / 2, Xwindow::Red);
		}
		if (cpType == 'Q'){
			screen->fillRectangle(xCord , yCord, cellSize / 3, cellSize / 2, Xwindow::Red);
		}
		if (cpType == 'K'){
			screen->fillRectangle(xCord , yCord, cellSize / 3.5, cellSize / 2, Xwindow::Red);
		}
		if (cpType == 'P'){
			screen->fillRectangle(xCord , yCord, 1, cellSize / 2, Xwindow::Red);
		}
	}
	else {
		if (cpType == 'R'){
			screen->fillRectangle(xCord , yCord, cellSize/ 1.5, cellSize / 2, Xwindow::Blue);
		}
		if (cpType == 'N'){
			screen->fillRectangle(xCord , yCord, cellSize / 2, cellSize / 2, Xwindow::Blue);
		}
		if (cpType == 'B'){
			screen->fillRectangle(xCord , yCord, cellSize / 2.5, cellSize / 2, Xwindow::Blue);
		}
		if (cpType == 'Q'){
			screen->fillRectangle(xCord , yCord, cellSize / 3, cellSize / 2, Xwindow::Blue);
		}
		if (cpType == 'K'){
			screen->fillRectangle(xCord , yCord, cellSize / 3.5, cellSize / 2, Xwindow::Blue);
		}
		if (cpType == 'P'){
			screen->fillRectangle(xCord , yCord, 1, cellSize / 2, Xwindow::Blue);
		}
	}
}

void GraphicsDisplay::drawColourSqr(int r, int c) {
	char colour = getCellColor(r, c);
	if (colour == 'B') {
		screen->fillRectangle(leftPad + cellSize * c , topPad + c * cellSize, cellSize, cellSize, Xwindow::Black);	
	}
	else {
		screen->fillRectangle(leftPad + cellSize * r , topPad + c * cellSize, cellSize, cellSize, Xwindow::White);		
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

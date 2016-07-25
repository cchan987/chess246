#include "window.h"
#include "graphicsdisplay.h"
#include "posn.h"
#include "chesspiece.h"
#include "observer.h"
#include <string>
#include <iostream>

using namespace std;

void GraphicsDisplay::notifyBoard(ChessPiece *cp, Posn dst) {
	if (cp == nullptr) {
		drawColourSqr(dst.getRow(), dst.getCol());
	}
	else {
		Posn src = cp->getPosition();
		cout << "gfx heard the notification of board update" << endl;
		cout << "1" << endl;
		drawColourSqr(src.getRow(), src.getCol());
		cout << "2" << endl;
		drawColourSqr(dst.getRow(), dst.getCol());
		cout << "3" << endl;
		drawPiece(cp, dst);
		cout << "4" << endl;		
	}
}

void GraphicsDisplay::notifyInfoMsg(string msg) {
	clearInfoBox();
	//screen->drawString(stringXcord, stringYcord, msg);
}

void GraphicsDisplay::clearInfoBox() {
	//screen->fillRectangle(stringXcord, stringYcord, 100, 20, Xwindow::Blue);
}

void GraphicsDisplay::drawPiece(ChessPiece *cp, Posn location) {
	char cpType = cp->getPieceType();
	char cpColour = cp->getColour();
	cout << "drawing colour, piece: " << cpColour << cpType << endl;

	// gets the centre of the cell that you want to draw in
	int xCord = leftPad + location.getCol() * cellSize + cellSize/2;
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
	char colour = getCellColour(r, c);

	if (colour == 'B') {
		float blackDrawPosX = leftPad + cellSize * c;
		float blackDrawPosY = topPad + cellSize * r;
		//cout << "drawing sqr of colour: black. Drawing at row, col: " << r << c << "cords: " << blackDrawPosX << ", " << blackDrawPosY << endl;
		screen->fillRectangle( blackDrawPosX, blackDrawPosY, cellSize, cellSize, Xwindow::Black);	
	}
	else {
		float whiteDrawPosX = leftPad + cellSize * c;
		float whiteDrawPosY = topPad + cellSize * r;
		//cout << "drawing sqr of colour: white. Drawing at row, col: " << r << c << "cords: " << whiteDrawPosX << ", " << blackDrawPosY << endl;
		screen->fillRectangle(whiteDrawPosX, whiteDrawPosY, cellSize, cellSize, Xwindow::White);		
	}
}

GraphicsDisplay::GraphicsDisplay() {
	screen = new Xwindow();
	screen->fillRectangle(0,0,500,500, Xwindow::Green);
}

GraphicsDisplay::~GraphicsDisplay(){
	delete screen;
}

void GraphicsDisplay::clearScreen() {
	screen->fillRectangle(0,0,500,500, Xwindow::Green);
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

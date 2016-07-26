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
		drawColourSqr(src.getRow(), src.getCol());
		drawColourSqr(dst.getRow(), dst.getCol());
		drawPiece(cp, dst);	
	}
}

void GraphicsDisplay::notifyInfoMsg(string msg) {
	clearInfoBox();
	screen->drawString(100, 50, msg);
}

void GraphicsDisplay::clearScreen() {
	screen->fillRectangle(0,0,500,500, Xwindow::Green);
}

void GraphicsDisplay::clearInfoBox() {
	screen->fillRectangle(0, 0, 500, 100, Xwindow::Green);
}

void GraphicsDisplay::drawPiece(ChessPiece *cp, Posn location) {
	char cpType = cp->getPieceType();
	char cpColour = cp->getColour();
	//cout << "drawing colour, piece: " << cpColour << cpType << endl;

	// gets the centre of the cell that you want to draw in
	int xCord = leftPad + location.getCol() * cellSize;
	int yCord = topPad + location.getRow() * cellSize;

	if (cpType == 'R'){
		drawRook(xCord, yCord, cpColour);
		//screen->fillRectangle(xCord , yCord, cellSize/ 1.5, cellSize / 2, Xwindow::Red);
	}
	if (cpType == 'N'){
		drawKnight(xCord, yCord, cpColour);
		//screen->fillRectangle(xCord , yCord, cellSize / 2, cellSize / 2, Xwindow::Red);
	}
	if (cpType == 'B'){
		drawBishop(xCord, yCord, cpColour);
		//screen->fillRectangle(xCord , yCord, cellSize / 2.5, cellSize / 2, Xwindow::Red);
	}
	if (cpType == 'Q'){
		drawQueen(xCord, yCord, cpColour);
		//screen->fillRectangle(xCord , yCord, cellSize / 3, cellSize / 2, Xwindow::Red);
	}
	if (cpType == 'K'){
		drawKing(xCord, yCord, cpColour);
		//screen->fillRectangle(xCord , yCord, cellSize / 3.5, cellSize / 2, Xwindow::Red);
	}
	if (cpType == 'P'){
		drawPawn(xCord, yCord, cpColour);
		//screen->fillRectangle(xCord , yCord, 1, cellSize / 2, Xwindow::Red);
	}
}


//r and c represent pixels of top right of the cell
void GraphicsDisplay::drawRook(int r, int c, char colour) {
	// base
	screen->fillRectangle(r + cellSize * 0.3, c + cellSize * 0.5, cellSize * 0.4, cellSize * 0.4, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	//left tower
	screen->fillRectangle(r + cellSize * 0.3, c + cellSize * 0.4, cellSize * 0.1, cellSize * 0.2, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	//right tower
	screen->fillRectangle(r + cellSize * 0.6, c + cellSize * 0.4, cellSize * 0.1, cellSize * 0.2, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
}

void GraphicsDisplay::drawKnight(int r, int c, char colour) {
	// base
	screen->fillRectangle(r + cellSize * 0.3, c + cellSize * 0.5, cellSize * 0.4, cellSize * 0.4, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	// neck
	screen->fillRectangle(r + cellSize * 0.6, c + cellSize * 0.4, cellSize * 0.1, cellSize * 0.2, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	// head
	screen->fillRectangle(r + cellSize * 0.3, c + cellSize * 0.3, cellSize * 0.4, cellSize * 0.1, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
}

void GraphicsDisplay::drawBishop(int r, int c, char colour) {
	// base
	screen->fillRectangle(r + cellSize * 0.3, c + cellSize * 0.5, cellSize * 0.4, cellSize * 0.4, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	// neck
	screen->fillRectangle(r + cellSize * 0.4, c + cellSize * 0.3, cellSize * 0.2, cellSize * 0.2, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	// head
	screen->fillRectangle(r + cellSize * 0.45, c + cellSize * 0.2, cellSize * 0.1, cellSize * 0.2, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
}

void GraphicsDisplay::drawQueen(int r, int c, char colour) {
	// base
	screen->fillRectangle(r + cellSize * 0.3, c + cellSize * 0.5, cellSize * 0.4, cellSize * 0.4, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	// neck
	screen->fillRectangle(r + cellSize * 0.35, c + cellSize * 0.3, cellSize * 0.3, cellSize * 0.2, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	// crown left spike
	screen->fillRectangle(r + cellSize * 0.35, c + cellSize * 0.2, cellSize * 0.1, cellSize * 0.2, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	// crown right spike
	screen->fillRectangle(r + cellSize * 0.55, c + cellSize * 0.2, cellSize * 0.1, cellSize * 0.2, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
}

void GraphicsDisplay::drawKing(int r, int c, char colour) {
	// base
	screen->fillRectangle(r + cellSize * 0.3, c + cellSize * 0.5, cellSize * 0.4, cellSize * 0.4, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	// vertical cross
	screen->fillRectangle(r + cellSize * 0.45, c + cellSize * 0.2, cellSize * 0.1, cellSize * 0.4, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	// horizontal cross
	screen->fillRectangle(r + cellSize * 0.4, c + cellSize * 0.3, cellSize * 0.2, cellSize * 0.1, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
}
void GraphicsDisplay::drawPawn(int r, int c, char colour) {
	// base
	screen->fillRectangle(r + cellSize * 0.3, c + cellSize * 0.5, cellSize * 0.4, cellSize * 0.2, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
	// head
	screen->fillRectangle(r + cellSize * 0.4, c + cellSize * 0.4, cellSize * 0.2, cellSize * 0.3, colour == 'B' ? Xwindow::Red : Xwindow::Blue);
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



void GraphicsDisplay::setDimensions(int dim) {
	dimension = dim;
	cellSize = width / dimension;

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			drawColourSqr(i, j);
		}
	}

	int columnLabelOffset = leftPad - 10;
	int rowLabelOffset = topPad + 300 + 20;

	screen->drawString(columnLabelOffset, 120 , "8");
	screen->drawString(columnLabelOffset, 120 + cellSize * 1 , "7");
	screen->drawString(columnLabelOffset, 120 + cellSize * 2 , "6");
	screen->drawString(columnLabelOffset, 120 + cellSize * 3 , "5");
	screen->drawString(columnLabelOffset, 120 + cellSize * 4 , "4");
	screen->drawString(columnLabelOffset, 120 + cellSize * 5 , "3");
	screen->drawString(columnLabelOffset, 120 + cellSize * 6 , "2");
	screen->drawString(columnLabelOffset, 120 + cellSize * 7 , "1");

	screen->drawString(120 + cellSize * 0, rowLabelOffset, "A");
	screen->drawString(120 + cellSize * 1, rowLabelOffset, "B");
	screen->drawString(120 + cellSize * 2, rowLabelOffset, "C");
	screen->drawString(120 + cellSize * 3, rowLabelOffset, "D");
	screen->drawString(120 + cellSize * 4, rowLabelOffset, "E");
	screen->drawString(120 + cellSize * 5, rowLabelOffset, "F");
	screen->drawString(120 + cellSize * 6, rowLabelOffset, "G");
	screen->drawString(120 + cellSize * 7, rowLabelOffset, "H");
}

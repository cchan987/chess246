#include "window.h"
#include "graphicsDisplay.h"
#include "cell.h"

using namespace std;

void GraphicsDisplay::notify(Cell &c) {
	int sqrY = leftPad + cellSize * c.getRow() + c.getRow();
	int sqrX = topPad + cellSize * c.getCol() + c.getCol();
	if (c.getState()) { // make square black
		screen->fillRectangle(sqrX, sqrY, cellSize, cellSize, Xwindow::Black);
	}
	else {  // make square white
		screen->fillRectangle(sqrX, sqrY, cellSize, cellSize, Xwindow::White);
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
			screen->fillRectangle(leftPad + cellSize * i + i , topPad + j * cellSize + j, cellSize, cellSize, Xwindow::White);	
		}
	}
}

SubscriptionType GraphicsDisplay::subType() { 
	return SubscriptionType::All;
}

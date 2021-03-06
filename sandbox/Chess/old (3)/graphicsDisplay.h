#ifndef __GFX_H__
#define __GFX_H__
#include "observer.h"

class Xwindow;
class Cell;

class GraphicsDisplay: public Observer {
	float cellSize;
	const int width = 300;
	const int leftPad = 100;
	const int topPad = 100;
	int dimension;
	Xwindow *screen;
	void drawPiece(ChessPiece &cp);
	void drawColourSqr(int r, int c);

public:
	GraphicsDisplay(Xwindow &w);
	~GraphicsDisplay();
	void setDimensions(int dim);
	void clearScreen();
	void notifyBoard(ChessPiece *cp, Posn dst) override; 
	void notifyInfoMsg(String msg) override;
};

#endif

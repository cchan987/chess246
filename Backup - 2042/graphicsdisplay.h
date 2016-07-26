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
	void drawPiece(ChessPiece *cp, Posn location);
	void drawRook(int r, int c, char colour);
	void drawKnight(int r, int c, char colour);
	void drawBishop(int r, int c, char colour);
	void drawQueen(int r, int c, char colour);
	void drawKing(int r, int c, char colour);
	void drawPawn(int r, int c, char colour);
	void drawColourSqr(int r, int c);

public:
	GraphicsDisplay();
	~GraphicsDisplay();
	void setDimensions(int dim);
	void clearScreen();
	void clearInfoBox();
	void notifyBoard(ChessPiece *cp, Posn dst) override; 
	void notifyInfoMsg(std::string msg) override;
};

#endif

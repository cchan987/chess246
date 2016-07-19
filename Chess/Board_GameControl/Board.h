#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <vector>
#include <string>

#include "GameControl.h"

#include "ChessPiece.h"

#include "Observer.h"
#include "TextDisplay.h"
#include "GraphDisplay.h"

class Board{
public:

	vector<vector<ChessPiece *>> theBoard;

	ChessPiece *getPieceByPosn(Posn p)
	Observer observer;
	TextDisplay textDisplay;
	GraphDisplay graphDisplay;
	vector<Move> getAllLegalMovesByColour(char colour);
	vector<ChessPiece *> getAllPiecesByColour(char colour);
	bool isACapturingMove(Move m);
	bool isACheckingMove(Move m);
	bool checkLegalMove(Posn p, ChessPiece cp); // Will be passed a move and return true if legal
	void moveChess(Posn p1, Posn p2); // Will be handed a legal move and execute it
	bool isInCheck(ChessPiece cp);
	
	bool isGameOver();
	bool checkMate();
	bool staleMate();

	void notifyBoard(Posn p, ChessPiece cp);
	void notifyInfoMsg(std::string s);
	
};
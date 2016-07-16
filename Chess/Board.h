#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <vector>
#include <string>

#include “GameControl.h”

#include “ChessPiece.h”

#include “Observer.h”
#include “TextDisplay.h”
#include “GraphDisplay.h”



class Board;

class Board{
public:

	Vector boardSize;

	Observer observer;
	TextDisplay textDisplay;
	GraphDisplay graphDisplay;

	checkLegalMove(Posn p, ChessPiece cp);
	moveChess(Posn p1, Posn p2);
	isInCheck(ChessPiece cp);
	
	isGameOver();
	checkMate();
	staleMate();

	notifyBoard(Posn p, ChessPiece cp);
	notifyInfoMsg(std::string s);
	
};
#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <iostream>
#include <sstream>

#include <ChessPiece.h>
#include <TextDisplay.h>
#include <GraphDisplay.h>


class Board
{
	public:
	Board();	
	~Board();
	vector<vector<ChessPiece *>> theBoard;
	void setupBoard();
	void printBoard(vector<vector<char> > );
	ChessPiece *getPieceByPosn(Posn p)
	Observer observer;
	TextDisplay textDisplay;
	GraphDisplay graphDisplay;
	//vector<Move> getAllLegalMovesByColour(char colour);
	vector<Move> getAllPossibleMovesByColour(char colour);
	vector<ChessPiece *> getAllPiecesByColour(char colour);
	bool isACapturingMove(Move m);
	bool isACheckingMove(Move m);
	bool checkLegalMove(Move m); // Will be passed a possible move and return true if legal
	void moveChess(Move m); // Will be handed a legal move and execute it
	bool isInCheck(ChessPiece cp);
	
	bool isGameOver();
	bool checkMate();
	bool staleMate();

	void notifyBoard(Posn p, ChessPiece cp);
	void notifyInfoMsg(std::string s);
	
};


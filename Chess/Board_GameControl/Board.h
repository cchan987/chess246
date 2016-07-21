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
	void placePiece();
	void removePiece(ChessPiece *piece);

	vector<vector<ChessPiece *>> theBoard;
	void setupBoard();
	void printBoard();
	ChessPiece *getPieceByPosn(Posn p)
	vector<Observer *> observerList;
	TextDisplay *td;
	GraphDisplay *graphDisplay;
	//vector<Move> getAllLegalMovesByColour(char colour);
	vector<Move> getAllPossibleMovesByColour(char colour);
	vector<ChessPiece *> getAllPiecesByColour(char colour);
	bool isACapturingMove(Move m);
	bool isACheckingMove(Move m);

	// Will be passed a possible move and return true if legal
	// A legal move is a possible move that:
	// -doesn't put your own king in check,
	// -doesn't capture your own piece
	bool checkLegalMove(Move m); 
	void executeMove(Move m); // Will be handed a legal move and execute it
	bool isInCheck(ChessPiece cp);
	
	bool isGameOver();
	bool checkMate();
	bool staleMate();

	void notifyBoard(Posn p, ChessPiece cp);
	void notifyInfoMsg(std::string s);
	
};

#endif

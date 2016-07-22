#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <iostream>
#include <sstream>

#include "chesspiece.h"
#include "textdisplay.h"



class Board
{
	public:
	Board();
	~Board();
	void placePiece(ChessPiece *piece);
	void removePiece(ChessPiece *piece);

	std::vector<std::vector<ChessPiece *>> theBoard;
	std::vector<int> posntran(std::string s1);
	bool createChessPiece(std::string s1,int x,int y);

	void printBoard();
	ChessPiece *getPieceByPosn(Posn p);
	
	//std::vector<Move> getAllLegalMovesByColour(char colour);
	std::vector<Move> getAllPossibleMovesByColour(char colour);
	std::vector<ChessPiece *> getAllPiecesByColour(char colour);
	bool isACapturingMove(Move m);
	bool isACheckingMove(Move m);

	// Will be passed a possible move and return true if legal
	// A legal move is a possible move that:
	// -doesn't put your own king in check,
	// -doesn't capture your own piece
	bool checkLegalMove(Move m); 
	void executeMove(Move m); // Will be handed a legal move and execute it
	bool isInCheck(char colour); // Will determine if player of 'colour' is in check
	
	bool isGameOver();
	bool checkMate();
	bool staleMate();

	void notifyBoardChange(ChessPiece *piece, Posn p);
	void notifyInfoMsgChange(std::string s);
	
};

#endif
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

	vector<vector<char> > gameBoard;
		
	void setupBoard();
	void printBoard(vector<vector<char> > );

	void checkLegalMove(Posn p, ChessPiece cp);
	void moveChess(Posn p1,Posn p2);
	void isInCheck(ChessPiece cp);
	void notifyBoard(Posn p,ChessPiece cp);
	void notifyInfoMsg(std::string s);

	private:
	

};

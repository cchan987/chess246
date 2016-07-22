#ifndef __GAMECONTROL_H__
#define __GAMECONTROL_H__

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "board.h"

class TextDisplay;
class Observer;

class GameControl
{	
	char whoseTurn = 'W';
	Board theBoard;
	TextDisplay *td;
	//GraphicsDisplay *gd;
	std::vector<Observer *> observerList;
	public:
	GameControl();
	~GameControl();
	void getHumanMove(char whoseTurn);
	void getNextMove(int player);
	void notifyBoardChange(ChessPiece *piece, Posn p);
	void notifyInfoMsgChange(std::string s);
	void removePiece(ChessPiece *piece);
	void placePiece(ChessPiece *piece);
	bool executeMove(Move m);
	std::vector<int> posntran(std::string xy);
	bool createChessPiece(std::string piece, int x, int y);
	void initBoard();
	void switchOn();
	void selectGameMode();
	void getNextMove(Board aBoard);
	void alternateTurn();
	void printScore();
	void startGame(int player1, int player2);
	bool isGameOver();
	void checkMate();
	void staleMate();
	void resign();
	void setupBoard();
	void endGame();
	int playerAI(std::string s1);

	private:
	int whiteScoreCount;
	int blackScoreCount;

};

#endif

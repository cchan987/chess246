#ifndef __GAMECONTROL_H__
#define __GAMECONTROL_H__

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "abstractAI.h"

#include "board.h"

class GraphicsDisplay;
class TextDisplay;
class Observer;

class GameControl
{	
	char whoseTurn = 'W';
	bool customBoard = false;
	bool resign = false;
	Board theBoard;
	AbstractAI* aiplayer;
	AbstractAI* aiplayer2;
	TextDisplay *td;
	GraphicsDisplay *gd;
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
	bool executeMove(Move m, char promotion = '0');

	std::vector<int> posntran(std::string xy);
	bool createChessPiece(std::string piece, int x, int y);
	void initBoard();
	void switchOn();

	//void selectGameMode();
	void getNextMove(Board aBoard);
	void alternateTurn();
	void printScore();
	void startGame(int player1, int player2);
	bool isGameOver();
	//void checkMate();
	//void staleMate();
	//void resign();
	
	bool checkSetupCondition();
	void setupBoard();
	void resetBoard();
	//void endGame();

	int playerAI(std::string s1, char colour);
	void startAIGame();
	int twoPlayerAI(std::string aComputer, std::string aComputer2);

	private:
	int whiteScoreCount;
	int blackScoreCount;

};

#endif

#ifndef __GAMECONTROL_H__
#define __GAMECONTROL_H__

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "board.h"


class GameControl
{
	public:
	GameControl();
	void switchOn();
	void selectGameMode();
	void getNextMove(Board aBoard);
	void alternateTurn();
	void printScore();
	void startGame(int player1, int player2);
	void isGameOver();
	void checkMate();
	void staleMate();
	void resign();
	void endGame();
	int playerAI(std::string s1);

	private:
	int whiteScoreCount;
	int blackScoreCount;

};

#endif

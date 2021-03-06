#ifndef __GAMECONTROL_H__
#define __GAMECONTROL_H__

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include <Board.h>


class GameControl
{
	public:

	void switchOn();
	void selectGameMode();
	void getNextMove();
	void alternateTurn();
	void printScore();
	void startGame();
	void isGameOver();
	void checkMate();
	void staleMate();
	void resign();
	void endGame();

	private:
	int whiteScoreCount;
	int blackScoreCount;

};

#endif

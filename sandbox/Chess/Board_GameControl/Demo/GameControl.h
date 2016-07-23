#ifndef __GAMECONTROL_H__
#define __GAMECONTROL_H__

#include <iostream>
#include <string>


class GameControl;

class GameControl{
private:
	int scoreCount;
	//int countTurn;
	char whoseTurn;

public:
	gameMode();
	setupBoard();

	startGame();
	initBoard();

	alternateTurn();
	resign();

	endGame();
	printScore();
			
};
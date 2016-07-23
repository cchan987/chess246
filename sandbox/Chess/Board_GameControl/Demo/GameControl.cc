#include <iostream>
#include <string>

#include <GameControl.h>

using namespace std;

GameControl::GameControl(){}

//respond is the arg in commend line, to be implemented…

void GameControl::gameMode(){
//determinate the game mode, player vs player?, player vs computer, computer vs computer

	if (respond == ’pvp’){

	}
	else if (respond == ‘pvc’){
	
	}
	else if (respond == ‘cvc’){

	}
	else{
	cout<<‘invalid’<<respond;
	}
}

void GameControl::setupBoard(){
	while(respond != ‘done’){
		respond[0]; // + - =
		respond[1]; // K,Q,R,N,P,B
		respond[2]; // position	
	}
	notify();
	cout<<“the setup stage is done”<<endl;
}

void GameControl::checkPieceNum(){

}

void GameControl::startGame(){
	initBoard();
}

void GameControl::initBoard(){
	//ctor create new board obj or clear board;
	//set dimension 8*8;
	whoseTurn = ‘W’;
	countTurn = 0;
}

void GameControl::alternateTurn(int turnCount){
	if (turnCount % 2 == 0) {
		return 'W';
	}
	else {
		return 'B';
	}
}

void GameControl::resign(){
	char me = this->whoseTurn;
	if (me == ‘B’){
	notify();
	cout<<‘White wins’<<endl;
	whitescore+=1;
	endGame();
	}
	else
	notify();
	cout<<‘Black wins’<<endl;
	blackscore+=1;
	endGame();
}

void GameControl::endGame(){
	notify();	
	//who win who lost?
}


void GameControl::printScore(){
	cout<<“score…”<<endl;
}

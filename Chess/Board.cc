#include <iostream>
#include <string>
#include <vector>

#include <Board.h>

using namespace std;

Board::Board(){}

void Board::checkLegalMove(Posn p, ChessPiece cp){

}

void Board::moveChess(Posn p1, Posn p2){

}

void isInCheck(ChessPiece cp){

}

Boolean isGameOver(){
	//check possible move from all chesspieces

	if( isInCheck() ){
		checkMate();
	}
	else{
		staleMate();
	}	
}

Boolean checkMate(){
	notifyGame_update_score();
}

Boolean staleMate(){
	notifyGame_update_score();
}

notifyBoard(Posn p, ChessPiece cp){
	//make use of text display 
}

notifyInfoMsg(std::string){
	//make use of text display 
}

#include <iostream>
#include <string>
#include <vector>
#include "move.h"
#include "Board.h"

using namespace std;

Board::Board(){}

vector<Move> Board::getAllLegalMovesByColour(char colour) {
	vector<Move> allLegalMoves;
	vector<ChessPiece *> thePieces = getAllLegalPiecesByColour(colour);
	for (int i = 0; i < thePieces.size(); ++i) {
		ChessPiece *currentPiece = thePieces[i];
		vector<Move> currentPieceMoves = currentPiece->getPossibleMoves();
		for (int i = 0; i < currentPieceMoves; ++i) {
			if (checkLegalMove(currentPieceMoves[i], currentPiece)) {
				allLegalMoves.emplace_back(currentPieceMoves[i]);
			}
		}
	}
	return allLegalMoves;
}

vector<ChessPiece *> Board::getAllPiecesByColour(char colour) {
	vector<ChessPiece *> pieceVector;
	for (int i = 0; i < theBoard.size(); i++) {
		for (int j = 0; j < theBoard[i].size(); j++) {
			ChessPiece *current_piece = theBoard[i][j];
			if (current_piece && current_piece->getColour() == colour) {
				pieceVector.emplace_back(current_piece);
			}
		}
	}
	return pieceVector;
}

//Checks if a given chesspiece can move to a given position
bool Board::checkLegalMove(Move m, ChessPiece cp){  
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

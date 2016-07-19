#include <iostream>
#include <string>
#include <vector>
#include "move.h"
#include "Board.h"

using namespace std;

Board::Board(){}

ChessPiece *Board::getPieceByPosn(Posn p) {
	int dstRow = moveDst.getRow();
	int dstCol = moveDst.getCol();
	return theBoard[dstRow][dstCol];
}

// m must be a legal move, therefore m will not have a destination
// that is occupied by a friendly piece, Will return true if an 
// opposing piece is in the destination square (including king)
bool Board::isACapturingMove(Move m) {
	Posn moveDst = m.getDestination();
	ChessPiece *dst = getPieceByPosn(moveDst);
	if (dst) {
		return true;
	}
	else {
		return false;
	}
}

// m must be a legal move, therefore m will not have a destination
// that is occupied by a friendly piece
bool Board::isACheckingMove(Move m) {
	Posn moveDst = m.getDestination();
	ChessPiece *thePiece = m.getPiece();
	vector<Move> futureMoves = getLegalMovesByPiece(thePiece);
	for (int i = 0; i < futureMoves.size(); ++i) {
		Move thisMove = futureMoves[i];
		if (isACapturingMove(thisMove)) {
			ChessPiece *threatenedPiece = getPieceByPosn(thisMove.getDestination());
			if (threatenedPiece.getPieceType() == "K") {
				return true;
			}
		}
	}
	return false;
}

vector<Move> getLegalMovesByPiece(ChessPiece *thePiece) {
	thePiece->getMoves();
}

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

void isInCheck(char colour){

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

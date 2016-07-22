
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

#include "board.h"

using namespace std;

ChessPiece *Board::getPieceByPosn(Posn p) {
	int dstRow = p.getRow();
	int dstCol = p.getCol();
	return theBoard[dstRow][dstCol];
}

// TODO check enpassant
bool Board::isLegalMove(Move m) {
  ChessPiece *thePiece = m.getPiece();
  Posn src = thePiece->getPosition();
  Posn dst = m.getDestination();
  ChessPiece *otherPiece = getPieceByPosn(dst);

  theBoard[src.getRow()][src.getCol()] = nullptr;
  theBoard[dst.getRow()][dst.getCol()] = thePiece;
  cout << "b4 is in check" << endl;
  bool goodMove = isInCheck(thePiece->getColour());
  cout << "after is in check" << endl;
  theBoard[src.getRow()][src.getCol()] = thePiece;
  theBoard[dst.getRow()][dst.getCol()] = otherPiece;
  return !(goodMove) ;
}


// Checks if the given coloured player is in check
bool Board::isInCheck(char colour) {
  cout << "b4 all possible" << endl;
  vector<Move> opponentMoves = getAllPossibleMovesByColour(colour == 'W'? 'B': 'W');
  cout << "after all possible" << endl;
  Posn myKingPosn(0,0);
  for (unsigned int i = 0; i < theBoard.size(); i++) {
    for (unsigned int j = 0; j < theBoard[i].size(); j++) {
        ChessPiece *currentPiece = theBoard[i][j];
        if(currentPiece){
          if (currentPiece->getPieceType() == 'K' && currentPiece->getColour() == colour){
            myKingPosn.setRow(i);
            myKingPosn.setCol(j);
          }
        }
      }
    }

  for (unsigned int i = 0; i < opponentMoves.size(); i++) {
    if (opponentMoves[i].getDestination() == myKingPosn) {
      return true;
    }
  }
  return false;
}

vector<ChessPiece *> Board::getAllPiecesByColour(char colour) {
  vector<ChessPiece *> friendlyPieces;
  for (unsigned int i = 0; i < theBoard.size(); i++) {
    for (unsigned int j = 0; j < theBoard[i].size(); j++) {
      if (theBoard[i][j]) {
        if (theBoard[i][j]->getColour() == colour) {
          friendlyPieces.emplace_back(theBoard[i][j]);
        }
      }
    }
  }
  return friendlyPieces;
}

// m must be a legal move, therefore m will not have a destination
// that is occupied by a friendly piece
/*
bool Board::isACheckingMove(Move m) {
	Posn moveDst = m.getDestination();
	ChessPiece *thePiece = m.getPiece();
	vector<Move> futureMoves = getLegalMovesByPiece(thePiece);
	for (int i = 0; i < futureMoves.size(); ++i) {
		Move thisMove = futureMoves[i];
		if (isACapturingMove(thisMove)) {
			ChessPiece *threatenedPiece = getPieceByPosn(thisMove.getDestination());
			if (threatenedPiece->getPieceType() == "K") {
				return true;
			}
		}
	}
	return false;
}

vector<Move> Board::getAllLegalMovesByColour(char colour, vector<vector<ChessPiece *>> testBoard) {
	vector<Move> allLegalMoves;
	vector <Move> currentPieceMoves = getAllPossibleMovesByColour(colour, testBoard);
		for (int i = 0; i < currentPieceMoves.size(); ++i) {
			if (checkLegalMove(currentMove)) {
				allLegalMoves.emplace_back(currentPieceMoves[i]);
			}
		}
	}
	return allLegalMoves;
}
*/
vector<Move> Board::getAllPossibleMovesByColour(char colour) {
	vector<Move> allPossibleMoves;
	vector<ChessPiece *> thePieces = getAllPiecesByColour(colour);
	for (unsigned int i = 0; i < thePieces.size(); ++i) {
		ChessPiece *currentPiece = thePieces[i];
		vector<Move> currentPieceMoves = currentPiece->getPossibleMoves(*this);
	}
	return allPossibleMoves;
}



Board::Board()
{

  //ctor
  
  int iRow = 8;
  int iCol = 8;
  
  for(int i = 0; i < iRow; ++i)
    {
    vector<ChessPiece *>temp;
    for(int j = 0; j < iCol; ++j)
      {
      temp.emplace_back(nullptr);
      }
    theBoard.emplace_back(temp);
    }


}



Board::~Board() {
  for (unsigned int i = 0; i < theBoard.size() ; ++i){
    for(unsigned int j = 0; j < theBoard[i].size(); ++j){
      delete theBoard[i][j];
    }
  }
}
  




/*
void Board::printBoard(vector<vector<char> > board){
  
  //edges
  vector<int>xaxis;
  for(int i = 0; i < 8; i++){ xaxis.push_back(i); }
  vector<int>yaxis;
  for(int i = 0; i < 8; i++){ yaxis.push_back(i); }

  //display for board + axis
  //y-axis
  for (int i=0; i<board.size(); i++){
    cout << yaxis[i]+1<<" ";
    for (int j=0; j<board[i].size(); j++){
      cout << board[i][j];
      //ChessPiece cp = chessboard[i][j].getType;
      //notify(cp);
    }
  cout << endl;
  }
  //x-axis
  cout << "  ";
  for (int i=0; i<board.size(); i++){cout <<"_"; }
  cout << endl;
  cout << "  ";
  for (int i=0; i<xaxis.size(); i++){ cout <<xaxis[i]+1;}
  cout << endl;

}*/


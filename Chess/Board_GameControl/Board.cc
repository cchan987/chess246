
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include <Board.h>

using namespace std;

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

vector<Move> Board::getAllLegalMovesByColour(char colour) {
	vector<Move> allLegalMoves;
	vector <Move> currentPieceMoves = getAllPossibleMovesByColour(colour);
		for (int i = 0; i < currentPieceMoves.size(); ++i) {
			if (checkLegalMove(currentMove)) {
				allLegalMoves.emplace_back(currentPieceMoves[i]);
			}
		}
	}
	return allLegalMoves;
}

vector<Move> getAllPossibleMovesByColour(char colour) {
	vector<Move> allPossibleMoves;
	vector<ChessPiece *> thePieces = getAllPiecesByColour(colour);
	for (int i = 0; i < thePieces.size(); ++i) {
		ChessPiece *currentPiece = thePieces[i];
		vector<Move> currentPieceMoves = currentPiece->getPossibleMoves();
	}
	return allPossibleMoves;
}

Board::Board()
{
  //ctor
  
  int iRow = 8;
  int iCol = 8;
  
  //initalize empty board
  vector<vector<char> > board;
  
  for(int i = 0; i < iRow; ++i)
    {
    vector<char>temp;
    for(int j = 0; j < iCol; ++j)
      {
      temp.push_back('-');
      }
    board.push_back(temp);
    }

  //initalize player's chess piece
  //p = pawns
  //n = knights
  //b = bishops
  //r = rooks
  //q = queens
  //k = king
  for(int i = 0; i<iRow; ++i){ board[6][i] = 'p'; }
  board[7][0] = 'r';
  board[7][1] = 'n';
  board[7][2] = 'b';
  board[7][3] = 'k';
  board[7][4] = 'q';
  board[7][5] = 'b';
  board[7][6] = 'n';
  board[7][7] = 'r';
  for(int i = 0; i<iCol; ++i){ board[1][i] = 'P';}
  board[0][0] = 'R';
  board[0][1] = 'N';
  board[0][2] = 'B';
  board[0][3] = 'K';
  board[0][4] = 'Q';
  board[0][5] = 'B';
  board[0][6] = 'N';
  board[0][7] = 'R';

  theBoard = board;
}

Board::~Board()
{
  int iRow = 8;
  int iCol = 8;
  for (int i = 0; i < iRow; ++i){
    for(int j = 0; i < iCol; ++j){
      delete theBoard[i][j];
      gameBoard[i][j] = 0;
    }
  }
}
  

Board::setupBoard(){

 bool done = false;

  while(!done){
    char c;
    char chessPiece;
    char x;
    char y;
    int x0;
    int y0;
    
    cerr << "Please edit the Board"<<endl;
    cin >> c;
    switch(c){
      
    case '+':
      cin >> chessPiece >> x >> y;
      //cout << chessPiece <<" " << x << " "<< y << endl;
      x0 = x - 48;
      y0 = y - 48;
      gameBoard[y0-1][x0-1] = chessPiece;
      printBoard(gameBoard);
      break;
      
    case '-':
      cin >> x >> y;
      x0 = x - 48;
      y0 = y - 48;
      gameBoard[y0-1][x0-1] = '-';
      printBoard(gameBoard);
      break;
      
    case 'q':
      done = true;
      break;
      
    }
  }

  
  gameBoard = board;

}

Bool Board::isInCheck(char colour){
}

Board::printBoard(vector<vector<char> > board){
  
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

}



Board::checkLegalMove(Posn p, ChessPiece cp){

}

Board::moveChess(Posn p1, Posn p2){

}


Board::notifyBoard(Posn p, ChessPiece cp){

}

Board::notifyInfoMsg(String s){

}


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
	td = new TextDisplay();
	observerList.emplace_back(td);
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

  for(int i = 0; i<iRow; ++i){ board[6][i] = new Pawn(‘B’, Posn(6, i)); }
  board[7][0] = new Rook('B', Posn(7, 0));
  board[7][1] = new Knight('B', Posn(7, 0));
  board[7][2] = new Bishop(‘B’, Posn(7, 2));
  board[7][3] = new King(‘B’, Posn(7, 3));
  board[7][4] = new Queen(‘B’, Posn(7, 4));
  board[7][5] = new Bishop(‘B’, Posn(7, 5));
  board[7][6] = new Knight(‘B’, Posn(7, 6));
  board[7][7] = new Rook(‘B’, Posn(7, 7));
  for(int i = 0; i<iCol; ++i){ board[1][i] = new Pawn(‘W’, Posn(1, i));}
  board[0][0] = new Rook(‘W’, Posn(0, 0));
  board[0][1] = new Knight(‘W’, Posn(0, 1));
  board[0][2] = new Bishop(‘W’, Posn(0, 2));
  board[0][3] = new King(‘W’, Posn(0, 3));
  board[0][4] = new Queen(‘W’, Posn(0, 4));
  board[0][5] = new Bishop(‘W’, Posn(0, 5));
  board[0][6] = new Knight(‘W’, Posn(0, 6));
  board[0][7] = new Rook(‘W’, Posn(0, 7));

  theBoard = board;
}

void Board::removePiece(ChessPiece *piece) {
	posn src = piece->getLocation();
	theBoard[src.getRow(), src.getCol()] = nullptr;
	notifyBoard(nullptr, src);
	delete piece;
}

void Board::placePiece(ChessPiece *piece) {
	Posn dst = piece->getLocation();
	theBoard[dst.getRow(), dst.getCol()] = piece;
	notifyBoard(piece, dst);
}

void Board::executeMove(Move m) {
	ChessPiece *thePiece = m.getPiece();
	Posn src = thePiece->getLocation();
	Posn dst = m.getDestination();
	ChessPiece *otherPiece = getPieceByPosn(dst);
	if (otherPiece) {
		removePiece(otherPiece);
	}
	piece.setLocation(dst);
	theBoard[dst.getRow(), dst.getCol()] = piece;
	notifyBoardChange(nullptr, src);
	notifyBoardChange(thePiece, dst);
}

Board::~Board() {
  int iRow = 8;
  int iCol = 8;
  for (int i = 0; i < iRow; ++i){
    for(int j = 0; i < iCol; ++j){
      delete theBoard[i][j];
      theBoard[i][j] = nullptr;
    }
  }
  delete td;
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

// Sends out notifications whenever the board is changed
// ChessPiece could be a nullptr, Position p has been set to the value of piece
Board::notifyBoardChange(ChessPiece *piece, Posn p) {
	for (int i = 0; i < observerList.size(); ++i) {
		observerList[i].notifyBoard(piece, p);
	}
}

Board::notifyInfoMsgChange(String s){

}

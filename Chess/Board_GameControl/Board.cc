
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

vector<Move> getAllPossibleMovesByColour(char colour, vector<vector<ChessPiece *>> testBoard) {
	vector<Move> allPossibleMoves;
	vector<ChessPiece *> thePieces = getAllPiecesByColour(colour, testBoard);
	for (int i = 0; i < thePieces.size(); ++i) {
		ChessPiece *currentPiece = thePieces[i];
		vector<Move> currentPieceMoves = currentPiece->getPossibleMoves();
	}
	return allPossibleMoves;
}

vector<ChessPiece *> getAllPiecesByColour(char colour, vector<vector<ChessPiece *>> testBoard) {
  vector<ChessPiece *> friendlyPieces;
  for (int i = 0; i < testBoard.size(); i++) {
    for (int j = 0; j < testBoard[i].size(); j++) {
      if (testBoard[i][j]) {
        if (testBoard[i][j].getColour() == colour) {
          friendlyPieces.emplace_back(testBoard[i][j]);
        }
      }
    }
  }
  return friendlyPieces;
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

vector<vector<ChessPiece *>> simulateMove() {
  
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
  

void Board::setupBoard(){

  bool done = false;
  
  while(done != true){

    cout << "Command: + / - / done" << endl;
    
    string setup_string;
    getline(cin,setup_string);
    istringstream setup_iss(setup_string);
    string setup_command;
    int count = 0;
    vector<string> listOfCommand;

    string piece;

    string position;


    
    while(setup_iss >> setup_command){
      listOfCommand.push_back(setup_command);
      ++count;
    }

    if (listOfCommand.size() == 0){
      cout << "Please Enter Command" << endl;
    }
    else{ 
      if (listOfCommand[0] == "+"){
	if (listOfCommand.size() != 3){
	  cout << "Invalid Setup Command Input; + chessPiece position" << endl;
	}
	else{
	  //do somthing, set piece
	  piece =  listOfCommand[1];
	  position = listOfCommand[2];
	  //setPiece();
	 if (posntran(position)[1] == -1){
	   cout << "position error" <<endl;
	   }
	else{
	  bool success = false;
	  success = createChess(piece,posntran(position)[0],posntran(position)[1]);
	  if(success != false){cout << "Set piece " << piece << " to " << position  << endl;}
	   }
	}
      }
      else if (listOfCommand[0] == "-"){
	if (listOfCommand.size() != 2){
	  cout << "Invalid Setup Command Input; - position" << endl;
	}
	else{
	  //do somthing, remove piece
	  position = listOfCommand[1];
	  //
	  if (posntran(position)[1] == -1){
           cout << "position error" <<endl;
          }
       	  else{
	  delete theBoard[posntran(position)[0]][posntran(position)[1]];
	  theBoard[posntran(position)[0]][posntran(position)[1]] = nullptr;
	  cout << "remove piece in " << posntran(position)[0]  << " " << posntran(position)[1] << endl;
	  }
	}
      }
      else if (listOfCommand[0] == "done"){
	//check condition
	int condition = 1;

	if (condition == 1){

	  done = true;
	}
	else{
	  
	  cout << "condition not satisified" << endl;

	  done = false;
	}
      }
      else{
	cout << "invalid setup input" << endl;
      }
    }
  }
}


vector<int> Board::posntran(string xy){

  string x = xy.substr(0,1);
  string y = xy.substr(1,1);
  string z = xy.substr(2);
  int xp,yp;

  xp = tolower(x[0]);
  yp = tolower(y[0]);

  xp = static_cast<int>(xp) - 'a';
  yp = static_cast<int>(yp) - '0' - 1;

  if( z!= "" || xp < 0 || xp > 7 || yp < 0 || yp > 7){
	xp = -1;
  }

  vector<int> posn;
  posn.push_back(yp);
  posn.push_back(xp);
  return posn;
}

bool Board::createChess(string piece, int x, int y){
	delete theBoard[x][y];
	theBoard[x][y] = nullptr;
	if (piece == "r"){cout << 'B' << " Rook in " << x << " " << y << endl; theBoard[x][y] = new Rook('B', Posn(x, y));}
	else if (piece == "n"){cout << 'B' << " Knight in " << x << " " << y << endl; theBoard[x][y] = new Knight(‘B’, Posn(x, y));}
	else if (piece == "b"){cout << 'B' << " Bishop in " << x << " " << y << endl; theBoard[x][y] = new Bishop(‘B’, Posn(x, y));}
	else if (piece == "k"){cout << 'B' << " King in " << x << " " << y << endl; theBoard[x][y] = new King(‘B’, Posn(x, y));}
	else if (piece == "q"){cout << 'B' << " Queen in " << x << " " << y << endl; theBoard[x][y] = new Queen(‘B’, Posn(x, y));}
	else if (piece == "R"){cout << 'W' << " Rook in " << x << " " << y << endl; theBoard[x][y] = new Rook(‘W’, Posn(x, y));}
	else if (piece == "N"){cout << 'W' << " Knight in " << x << " " << y << endl; theBoard[x][y] = new Knight(‘W’, Posn(x, y));}
	else if (piece == "B"){cout << 'W' << " Bishop in " << x << " " << y << endl; theBoard[x][y] = new Bishop(‘W’, Posn(x, y));}
	else if (piece == "K"){cout << 'W' << " King in " << x << " " << y << endl; theBoard[x][y] = new King(‘W’, Posn(x, y));}
	else if (piece == "Q"){cout << 'W' << " Queen in " << x << " " << y << endl; theBoard[x][y] = new Queen(‘W’, Posn(x, y));}
	else {cout << "chess type error" << endl; return false;}
	return true;
}




Bool Board::isInCheck(char colour){
}

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

}



bool Board::checkLegalMove(Posn p, ChessPiece cp){

}

// Sends out notifications whenever the board is changed
// ChessPiece could be a nullptr, Position p has been set to the value of piece
void Board::notifyBoardChange(ChessPiece *piece, Posn p) {
	for (int i = 0; i < observerList.size(); ++i) {
		observerList[i].notifyBoard(piece, p);
	}
}

void Board::notifyInfoMsgChange(String s){

}

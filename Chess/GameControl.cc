
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "textdisplay.h"
#include "gamecontrol.h"

using namespace std;

GameControl::GameControl()
{ 
  td = new TextDisplay();
  td->setDimensions(8);
  observerList.emplace_back(td);
  initBoard();
  //ctor
  whiteScoreCount = 0;
  blackScoreCount = 0;
  
}


// Sends out notifications whenever the board is changed
// ChessPiece could be a nullptr, Position p has been set to the value of piece
void GameControl::notifyBoardChange(ChessPiece *piece, Posn p) {
  for (unsigned int i = 0; i < observerList.size(); ++i) {
    observerList[i]->notifyBoard(piece, p);
  }
}

void GameControl::notifyInfoMsgChange(string s){

}


// Translates a string a1 to a coordinate on the board 7,0
vector<int> GameControl::posntran(string xy){
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

// Takes a string and cord then places a piece on board
bool GameControl::createChessPiece(string piece, int x, int y){
  removePiece(theBoard.getPieceByPosn(Posn(x,y)));
  if (piece == "r"){cout << 'B' << " Rook in " << x << " " << y << endl; placePiece(new Rook('B', Posn(x, y)));}
  else if (piece == "p"){cout << 'B' << " Pawn in " << x << " " << y << endl; placePiece(new Pawn('B', Posn(x, y)));}
  else if (piece == "n"){cout << 'B' << " Knight in " << x << " " << y << endl; placePiece(new Knight('B', Posn(x, y)));}
  else if (piece == "b"){cout << 'B' << " Bishop in " << x << " " << y << endl; placePiece(new Bishop('B', Posn(x, y)));}
  else if (piece == "k"){cout << 'B' << " King in " << x << " " << y << endl; placePiece(new King('B', Posn(x, y)));}
  else if (piece == "q"){cout << 'B' << " Queen in " << x << " " << y << endl; placePiece(new Queen('B', Posn(x, y)));}
  else if (piece == "R"){cout << 'W' << " Rook in " << x << " " << y << endl; placePiece(new Rook('W', Posn(x, y)));}
  else if (piece == "P"){cout << 'W' << " Pawn in " << x << " " << y << endl; placePiece(new Pawn('W', Posn(x, y)));}
  else if (piece == "N"){cout << 'W' << " Knight in " << x << " " << y << endl; placePiece(new Knight('W', Posn(x, y)));}
  else if (piece == "B"){cout << 'W' << " Bishop in " << x << " " << y << endl; placePiece(new Bishop('W', Posn(x, y)));}
  else if (piece == "K"){cout << 'W' << " King in " << x << " " << y << endl; placePiece(new King('W', Posn(x, y)));}
  else if (piece == "Q"){cout << 'W' << " Queen in " << x << " " << y << endl; placePiece(new Queen('W', Posn(x, y)));}
  else {cout << "chess type error" << endl; return false;}
  return true;
}

void GameControl::removePiece(ChessPiece *piece) {
  if (piece == nullptr) {
    return;
  }
  Posn src = piece->getPosition();
  theBoard.theBoard[src.getRow()][src.getCol()] = nullptr;
  notifyBoardChange(nullptr, src);
  delete piece;
}

void GameControl::placePiece(ChessPiece *piece) {
  Posn dst = piece->getPosition();
  theBoard.theBoard[dst.getRow()][dst.getCol()] = piece;
  notifyBoardChange(piece, dst);
}

void GameControl::initBoard() {
    //initalize player's chess piece
  int iRow = 8;
  int iCol = 8;
  for(int i = 0; i<iRow; ++i) { 
      placePiece(new Pawn('W', Posn(6, i))); 
    }

  placePiece(new Rook('W', Posn(7, 0)));
  placePiece(new Knight('W', Posn(7, 1)));
  placePiece(new Bishop('W', Posn(7, 2)));
  placePiece(new Queen('W', Posn(7, 3)));
  placePiece(new King('W', Posn(7, 4)));
  placePiece(new Bishop('W', Posn(7, 5)));
  placePiece(new Knight('W', Posn(7, 6)));
  placePiece(new Rook('W', Posn(7, 7)));

  for(int i = 0; i<iCol; ++i) { 
    placePiece(new Pawn('B', Posn(1, i)));
  }

  placePiece(new Rook('B', Posn(0, 0)));
  placePiece(new Knight('B', Posn(0, 1)));
  placePiece(new Bishop('B', Posn(0, 2)));
  placePiece(new Queen('B', Posn(0, 3)));
  placePiece(new King('B', Posn(0, 4)));
  placePiece(new Bishop('B', Posn(0, 5)));
  placePiece(new Knight('B', Posn(0, 6)));
  placePiece(new Rook('B', Posn(0, 7)));
}


void GameControl::setupBoard(){

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
      if (listOfCommand[0] == "+") { // ADD COMMAND
        if (listOfCommand.size() != 3) {
          cout << "Invalid Setup Command Input; + chessPiece position" << endl;
        }
        else {
          //do somthing, set piece
          piece =  listOfCommand[1];
          position = listOfCommand[2];
          //setPiece();
          if (posntran(position)[1] == -1) {
           cout << "position error" <<endl;
          }
          else {
            bool success = false;
            success = createChessPiece(piece,posntran(position)[0],posntran(position)[1]);
            if (success != false) { 
              cout << "Set piece " << piece << " to " << position  << endl;
              cout<< *td;
            }
          }
        }
      }

      else if (listOfCommand[0] == "-") { // REMOVE COMMAND
        if (listOfCommand.size() != 2) {
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
          removePiece(theBoard.getPieceByPosn(posntran(position)[0], posntran(position)[1]));
          cout << "remove piece in " << posntran(position)[0]  << " " << posntran(position)[1] << endl;
          cout << *td;
          }
        }
      }

      //TODO: Check that no ones is in check
      // Only one king for black and white
      // No pawns on first and last row
      else if (listOfCommand[0] == "done") { // DONE COMMAND 
        //check condition
        int condition = 1;

        if (condition == 1){
          cout << *td;
          done = true;
        }
        else{
          
          cout << "condition not satisified" << endl;

          done = false;
        }
      }

      else { // Bad command , try again
        cout << "invalid setup input" << endl;
      }
    }
  }
}

//==========================================================================
void GameControl::switchOn(){
  
  /*
  char whoseTurn;
  whoseTurn = 'W';
    */
  bool exitGame = false;
  
  while (exitGame != true){

  cout << "command: game/ setup / quit" << endl;
  
  string menu_string;
  getline(cin,menu_string);
  istringstream menu_iss(menu_string);
  string menu_command;
  int count = 0;
  vector<string> listOfCommand;

  string firstPlayer;
  string secondPlayer;
  
  //one time command
   while(menu_iss >> menu_command){
     listOfCommand.push_back(menu_command);
     ++count;
   }

   if (listOfCommand.size() == 0){
     cout << "Please Enter Command" << endl;
   }
   else{     
     if (listOfCommand[0] == "game"){
       if (listOfCommand.size() != 3){
	 cout << "Invalid Game Command Input; Please try again" << endl;
       }
       else{
	 firstPlayer = listOfCommand[1];
	 secondPlayer = listOfCommand[2];
	 if(firstPlayer == "human" && secondPlayer == "human"){
	   startGame(0, 0);
	 }
	 else if(firstPlayer.substr(0,8) == "computer" && secondPlayer.substr(0,8) == "computer"){
	   int player1level;
	   int player2level;
	   player1level = playerAI(firstPlayer);
	   player2level = playerAI(secondPlayer);
	   if(player1level!= -1 && player2level != -1){
	     startGame(player1level, player2level);
	   }
	 }
	 else if (firstPlayer == "human" && secondPlayer.substr(0,8) == "computer"){
	   int level;
	   level = playerAI(secondPlayer);
	   if(level!= -1){
	     startGame(0,level);
	   }
	 }
	 else if (secondPlayer == "human" && firstPlayer.substr(0,8) == "computer"){
	   int level;
	   level = playerAI(firstPlayer);
	   if(level!= -1){
	     startGame(level, 0);
	   }
	 }
	 else{
	   cout<< "Invalid Player Input" << endl;
	 }
       } 	   
     }
     else if (listOfCommand[0] == "setup"){       
       if (listOfCommand.size() != 1){
	 cout << "Invalid Setup Command input" << endl;
       }
       else{
	 cout << "enter setup mode" << endl;
	 setupBoard();      
       }
     }
     else if (listOfCommand[0] == "quit"){
       if (listOfCommand.size() != 1){
	 cout << "Invalid Quit Command input" << endl;
       }    
       else{
	 cout << "Exit game; Thank you for playing" << endl;
	 exitGame = true;
       }
     }
     else{
       cout << "Invalid Command Input Please try again" << endl;   
     }   
   }
  }


}








//In-Game Flow
//==========================================================================
/*
void GameControl::selectGameMode(){
  //This function is used to select game mode
  string firstPlayer,secondPlayer;
  getline(cin, firstPlayer);
  getline(cin, secondPlayer);
  if(firstPlayer && secondPlayer == "human"){
    gameMode == "pvp";
  }
  else if(firstPlayer && secondPlayer == "computer"){
    gameMode == "cvc";
  }
  else if ((firstPlayer == "human" && secondPlayer == "computer")||
	   (secondPlayer == "human" && firstPlayer == "computer")){
    gameMode == "pvc";
  }
  
}*/
//==========================================================================
  /*
void GameControl::getNextMove(Board aBoard){
  //prompt the user to type in next move and move the chess

  //cin >> command
  //move(commend)

  if (gameMode == "pvp"){

  }
  else if(gameMode == "pvc"){

  }
  else if(gameMode == "cvc"){

  }
  else{

  }

}*/

//==========================================================================
/*
void GameControl::alternateTurn(){
  //This function is used to alternate player turn
  if(whoseTurn == 'W')
    {
      whoseTurn == 'B';
    }
  else
    {
      whoseTurn == 'W';
    }
}*/
//==========================================================================

int GameControl::playerAI(string aComputer){
  if(aComputer.substr(8,1) == "1"){
     return 1;
  }
  else if(aComputer.substr(8,1) == "2"){
     return 2;
  }
  else if (aComputer.substr(8,1) == "3"){
     return 3;
  }
  else if (aComputer.substr(8,1) == "4"){
     return 4;
  }
  else {
    cout << "invalid computer level" << endl;
    return -1;
  }
}


//===========================================

void GameControl::printScore(){
  //This function prints the score
  int i1 = whiteScoreCount;
  int i2 = blackScoreCount;
  cout << i1 << endl;
  cout << i2 << endl;
}




//Main Flow functions
//==========================================================================
/*
void GameControl::startGame2(Board aBoard){
  //This function pass the current board to playboard
  //to start the game
  do{
    getNextMove(aBoard);
    alternateTurn();
  }
  while(! isGameOver());
  aBoard.printBoard();
  }
}
*/

//==========================================================================


//////FLAG//////////
/*
void GameControl::isGameOver(){
  //This function is used to determinate is it gmaevoer
  bool bCanMove(false);
  bCanMove = currentBoard.canMove(whoseTurn);
  if(! bCanMove){
    if(currentBoard.isInCheck(whoseTurn)) {
	alternateTurn();
	checkMate();
      }
      else{
	staleMate();
      }
      }
  }
}
*/

//==========================================================================
/*
void GameControl::checkMate(){
  //This function is used to consume a player, declare him to be winner, and update score count, print msg, ask for new game or quit to menu
  cout << "checkMate" << whoseTurn << "wins"<<endl;
  if(whoseTurn == 'W'){
    whiteScoreCount++;
  }
  else{
    blackScoreCount++;
  }
}
*/
//==========================================================================

void GameControl::staleMate(){
  //This function is used to declare stalemate
  cout << "staleMate" << endl;
}

//==========================================================================
/*
void GameControl::resign(){
  //This function is used when resign
  if(whoseTurn == 'W'){
    whiteScoreCount++;
  }
  else{
    blackScoreCount++;
  }
  
}*/

//==========================================================================

void GameControl::startGame(int player1, int player2){
  cout << "player1: " << player1 << " vs " << "player2: " <<player2 << endl;
 cout << "game end" << endl;
}




void::GameControl::endGame(){
  //This function is used to end Game
  //call destructor , delete the board
}


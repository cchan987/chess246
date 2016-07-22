
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include <GameControl.h>

using namespace std;

GameControl::GameControl()
{
  //ctor
  whiteScoreCount = 0;
  blackScoreCount = 0;
  
}




//==========================================================================
GameControl::switchOn(){
  
  Board defaultBoard;
  Board currentBoard;
  
  char whoseTurn;
  whoseTurn = 'W';

  
  printBoard(currentBoard);
    
  
  bool exit = false;
  
  while (exit != true){

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
	 currentBoard.setupBoard();      
       }
     }
     else if (listOfCommand[0] == "quit"){
       if (listOfCommand.size() != 1){
	 cout << "Invalid Quit Command input" << endl;
       }    
       else{
	 cout << "Exit game; Thank you for playing" << endl;
	 exit = true;
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
  
}
//==========================================================================
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

}

//==========================================================================

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
}
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

//==========================================================================


//////FLAG//////////

void GameControl::isGameOver(){
  //This function is used to determinate is it gmaevoer
  bool bCanMove(false);
  bCanMove = currentBoard.canMove(whoseTurn);
  if(! bCanMove){
    if(currentBoard.isInCheck(whoseTurn){
	alternateTurn();
	checkMate();
      }
      else{
	staleMate();
      }
      }
  }
}


//==========================================================================

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

//==========================================================================

void GameControl::staleMate(){
  //This function is used to declare stalemate
  cout << "staleMate" << endl;
}

//==========================================================================

void GameControl::resign(){
  //This function is used when resign
  if(whoseTurn == 'W'){
    whiteScoreCount++;
  }
  else{
    blackScoreCount++;
  }
  
}

//==========================================================================

void GameControl::startGame(int player1, int player2){
  cout << "player1: " << player1 << " vs " << "player2: " <<player2 << endl;
 cout << "game end" << endl;
}




void::GameControl::endGame(){
  //This function is used to end Game
  //call destructor , delete the board
}


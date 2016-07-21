
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "GameControl.h"

using namespace std;

GameControl::GameControl()
{
  //ctor
  whiteScoreCount = 0;
  blackScoreCount = 0;
  
}




//==========================================================================
GameControl::switchOn(){

  cout << "============command? game, setup============" << endl;
  
  //board initalized
  Board currentBoard;
  
  char whoseTurn;
  whoseTurn = 'W';

  string gameMode;
  gameMode = "";
  
  printBoard(currentBoard);
    
  //readin command
  string user_input;
  getline(cin,user_input);
  istringstream iss(user_input);
  string s;
  
  //read first command
  getline(iss,s,' ');
  if(s == "game"){
    cout<<"=============enter game mode================"<<endl;
    selectGameMode();
    startGame();
   }


  
  else if (s == "setup"){
    //setup Board
    cout<<"===========please setup the board==========="<<endl;
    currentBoard.setup();
    cout << "===============CURRENT BOARD======================="<<endl;
    currentBoard.printBoard();
  }



  
  else{
    cout << "===================invalid input==============" <<endl;
  } 



  endGame();
}








//In-Game Flow
//==========================================================================

GameControl::selectGameMode(){
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
GameControl::getNextMove(Board aBoard){
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

GameControl::alternateTurn(){
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


GameControl::printScore(){
  //This function prints the score
  int i1 = whiteScoreCount;
  int i2 = blackScoreCount;
  cout << i1 << endl;
  cout << i2 << endl;
}




//Main Flow functions
//==========================================================================

GameControl::startGame(Board aBoard){
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

GameControl::isGameOver(){
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

GameControl::checkMate(){
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

GameControl::staleMate(){
  //This function is used to declare stalemate
  cout << "staleMate" << endl;
}

//==========================================================================

GameControl::resign(){
  //This function is used when resign
  if(whoseTurn == 'W'){
    whiteScoreCount++;
  }
  else{
    blackScoreCount++;
  }
  
}

//==========================================================================


GameControl::endGame(){
  //This function is used to end Game
  //call destructor , delete the board
}



#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include "textdisplay.h"
#include "graphicsdisplay.h"
#include "gamecontrol.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

#include "abstractAI.h"
#include "botLvl1.h"
#include "botLvl2.h"
#include "botLvl3.h"
//#include "botLvl4.h"

#include <fstream>

using namespace std;

GameControl::GameControl()
{ 
  gd = new GraphicsDisplay();
  observerList.emplace_back(gd);
  td = new TextDisplay();
  td->setDimensions(8);
  observerList.emplace_back(td);
  //ctor
  whiteScoreCount = 0;
  blackScoreCount = 0;
  
}

GameControl::~GameControl() {
  delete td;
  delete gd;
  delete aiplayer;
  delete aiplayer2;
}


// Sends out notifications whenever the board is changed
// ChessPiece could be a nullptr, Position p has been set to the value of piece
void GameControl::notifyBoardChange(ChessPiece *piece, Posn p) {
  for (unsigned int i = 0; i < observerList.size(); ++i) {
    observerList[i]->notifyBoard(piece, p);
  }
}

void GameControl::notifyInfoMsgChange(string s){
  for (unsigned int i = 0; i < observerList.size(); ++i) {
    observerList[i]->notifyInfoMsg(s);
  }
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
  yp = 7 - yp;

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

// Can only be passed moves that were found in a pieces getPossibleMove return vector
// Makes the move happen if legal move, otherwise nothing
// Returns true if move was good, false otherwise
bool GameControl::executeMove(Move m, char promotion) {
  ChessPiece *thePiece = m.getPiece();
  Posn src = thePiece->getPosition();
  Posn dst = m.getDestination();
  ChessPiece *otherPiece = theBoard.getPieceByPosn(dst);

  ChessPiece *secondPiece = nullptr;
  Posn secondSrc(-1, -1);
  Posn secondDst(-1, -1);
  if (m.getIsCastlingMove()) {
    if (src.getCol() < dst.getCol()) { // right castling
      secondPiece = theBoard.theBoard[src.getRow()][7];
      secondSrc = secondPiece->getPosition();
      secondDst = Posn(dst.getRow(), dst.getCol() - 1);
    }
    else if (src.getCol() > dst.getCol()) { // left castling
      secondPiece = theBoard.theBoard[src.getRow()][0];
      secondSrc = secondPiece->getPosition();
      secondDst = Posn(dst.getRow(), dst.getCol() + 1);
    }
    else cout << "Castling Detection Error" << endl;
  }
  else if (m.getIsEnPassantCaptureMove()) {
    if (dst.getRow() == 2) { //white
      secondPiece = theBoard.theBoard[dst.getRow() + 1][dst.getCol()];
      secondSrc = secondPiece->getPosition();
    }
    else if (dst.getRow() == 5) { //black
      secondPiece = theBoard.theBoard[dst.getRow() - 1][dst.getCol()];
      secondSrc = secondPiece->getPosition();
    }
  }

//  cout << "b4 is legal" << endl;
  if (theBoard.isLegalMove(m)) {
  //  cout << "is legal is good" << endl;
    removePiece(otherPiece);
   // cout << "remove good" << endl;

	  theBoard.theBoard[src.getRow()][src.getCol()] = nullptr;
    theBoard.theBoard[dst.getRow()][dst.getCol()] = thePiece;
    thePiece->setPosition(dst);
    notifyBoardChange(nullptr, src);
    notifyBoardChange(thePiece, dst);

    if (m.getIsCastlingMove()) {
      theBoard.theBoard[secondSrc.getRow()][secondSrc.getCol()] = nullptr;
      theBoard.theBoard[secondDst.getRow()][secondDst.getCol()] = secondPiece;
      secondPiece->setPosition(secondDst);
      notifyBoardChange(nullptr, secondSrc);
      notifyBoardChange(secondPiece, secondDst);
    }
    else if (m.getIsEnPassantCaptureMove()) {
      removePiece(secondPiece);
    }

    if (theBoard.canBeCapturedEnPassant) {
      theBoard.canBeCapturedEnPassant->setEnPassantFlag(false);
      theBoard.canBeCapturedEnPassant = nullptr;
    }

    if (thePiece->getPieceType() == 'P') {
      thePiece->setMoved();
      if (src.getRow() - dst.getRow() == 2 || src.getRow() - dst.getRow() == -2) {
        thePiece->setEnPassantFlag(true);
        theBoard.canBeCapturedEnPassant = thePiece;
      }
      else if (dst.getRow() == 0 || dst.getRow() == 7) {
        //Promote Pawn
        removePiece(thePiece);
        if (promotion == 'R') {
          placePiece(new Rook(whoseTurn, Posn(dst.getRow(), dst.getCol())));
        }
        if (promotion == 'N') {
          placePiece(new Knight(whoseTurn, Posn(dst.getRow(), dst.getCol())));
        }
        if (promotion == 'B') {
          placePiece(new Bishop(whoseTurn, Posn(dst.getRow(), dst.getCol())));
        }
        if (promotion == 'Q') {
          placePiece(new Queen(whoseTurn, Posn(dst.getRow(), dst.getCol())));
        }
      }
    }

    return true;    
  }
  else {
    return false;
  }
}

void GameControl::removePiece(ChessPiece *piece) {
  if (piece == nullptr) {
    return;
  }
  Posn src = piece->getPosition();
  theBoard.theBoard[src.getRow()][src.getCol()] = nullptr;
  notifyBoardChange(nullptr, src);

  if (piece == theBoard.canBeCapturedEnPassant) theBoard.canBeCapturedEnPassant = nullptr;

  delete piece;
}

void GameControl::placePiece(ChessPiece *piece) {
  Posn dst = piece->getPosition();
  theBoard.theBoard[dst.getRow()][dst.getCol()] = piece;
  notifyBoardChange(piece, dst);
}

void GameControl::initBoard() {
  gd->clearScreen();
  gd->setDimensions(8);
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

  cout << "Board initalization completed" << endl;
}

//********************
/*void GameControl::loadFile(){
  string filesrc;
  getline(cin,filesrc);
  ifstream file(filesrc);
  string str;
  if(file){
    while (getline(file,str)){
      if(str != "setup"){
        setupBoard(str, true);
      }
    }
  }
  else{
    notifyInfoMsgChange("Read file error");
  }
}*/



void GameControl::setupBoard(bool load, string fileName) {

  ifstream file;
  if (load) {
    file.open(fileName);
  }

  bool done = false;
  
  while(done != true) {

  cout << "Command: + / - / = / done" << endl;
    
    string setup_string;

//***********************************
    if(load == false){
      getline(cin,setup_string);
    }
    else{
      getline(file,setup_string);
      if (file.fail()) break;
    }

//**********************************
    istringstream setup_iss(setup_string);
    string setup_command;
    int count = 0;
    vector<string> listOfCommand;

    string piece;

    string position;


    
    while(setup_iss >> setup_command)
    {
      listOfCommand.emplace_back(setup_command);
      ++count;
    }

    if (listOfCommand.size() == 0)
    {
      cout << "Please Enter Command" << endl;
    }
    else {

      if (listOfCommand[0] == "+") { // ADD COMMAND

        if (listOfCommand.size() != 3) {
		      cout << "Invalid Setup Command Input; + chessPiece position" << endl;
	      }
        else {
          //set piece
	        piece =  listOfCommand[1];
	        position = listOfCommand[2];
	        //setPiece();
	        if (posntran(position)[1] == -1) {
		        cout << "position error" <<endl;
		      }
	        else {
		        bool success = false;
		        success = createChessPiece(piece,posntran(position)[0],posntran(position)[1]);
		        if (success) { 
		          cout << "Set piece " << piece << " to " << position  << endl;

              /*if () {

              }*/

		          cout<< *td;
		        }
		      }
	      }
	    }
	    else if (listOfCommand[0] == "-") { // REMOVE COMMAND
	      if (listOfCommand.size() != 2) {
	        cout << "Invalid Setup Command Input; - position" << endl;
	      }	    
	      else {
		      //do somthing, remove piece
		      position = listOfCommand[1];
		      //
		      if (posntran(position)[1] == -1) {
		        cout << "position error" <<endl;
		      }
		      else {
		        removePiece(theBoard.getPieceByPosn(Posn(posntran(position)[0], posntran(position)[1])));
		        cout << "remove piece in " << posntran(position)[0]  << " " << posntran(position)[1] << endl;
		        cout << *td;
		      }
	      }
	    }
	    else if (listOfCommand[0] == "=") {
	      if (listOfCommand.size() != 2) {
		      cout << "invalid setup command; = colour, black or white" <<endl;
	      }
  	    else {
          if (listOfCommand[1] == "black")  { whoseTurn = 'B';}
          else if (listOfCommand[1] == "white")  {whoseTurn = 'W';}
          else {cout << "colour invalid, black or white" << endl;}
        }
      }
      else if (listOfCommand[0] == "done") {
	 if ( checkSetupCondition() ){
  		    cout << *td;
  		    done = true;
  		    customBoard = true;
        }
        else {
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

  bool exitGame = false;
  
  while (exitGame != true) {

    cout << "command: game/ setup / load / quit" << endl;
  
    string menu_string;
    getline(cin,menu_string);

    if (cin.eof()) {
      printScore();
      break;
    }

    istringstream menu_iss(menu_string);
    string menu_command;
    int count = 0;
    vector<string> listOfCommand;

    string firstPlayer;
    string secondPlayer;
  

  //one time command
   while (menu_iss >> menu_command){
     listOfCommand.push_back(menu_command);
     ++count;
   }

   if (listOfCommand.size() == 0){
     cout << "Please Enter Command" << endl;
   }
   else {     
     if (listOfCommand[0] == "game") {
        if (listOfCommand.size() != 3) {
          cout << "Invalid Game Command Input; Please try again" << endl;
        }
        else {
          firstPlayer = listOfCommand[1];
          secondPlayer = listOfCommand[2];
          if (firstPlayer == "human" && secondPlayer == "human") {
            startGame(0, 0);
          }
          else if (firstPlayer.substr(0,8) == "computer" && secondPlayer.substr(0,8) == "computer") {
	     int player;
	     player = twoPlayerAI(firstPlayer, secondPlayer);
            if (player != -1) {
              startAIGame();
            }
          }
          else if (firstPlayer == "human" && secondPlayer.substr(0,8) == "computer"){
            int level;
            level = playerAI(secondPlayer,'B');
            if (level!= -1) {
              startGame(0,level);
            }
          }
          else if (secondPlayer == "human" && firstPlayer.substr(0,8) == "computer") {
            int level;
            level = playerAI(firstPlayer,'W');
            if (level!= -1) {
              startGame(level, 0);
            }
          }
          else {
            cout<< "Invalid Player Input" << endl;
          }
        }
      }
      else if (listOfCommand[0] == "setup") {
        if (listOfCommand.size() != 1) {
          cout << "Invalid Setup Command input" << endl;
        }
        else {
          cout << "enter setup mode" << endl;
          //*****************************************************
          setupBoard();
        }
      }
      else if (listOfCommand[0] == "quit") {
        if (listOfCommand.size() != 1) {
          cout << "Invalid Quit Command input" << endl;
        }
        else {
          printScore();
          exitGame = true;
        }
      }
      //*******************************************
      else if (listOfCommand[0] == "load"){
        string f;
        cout << "Enter filename" << endl;
        cin >> f;
        setupBoard(true, f);
      }
      else {
        cout << "Invalid Command Input Please try again" << endl;
      }
    }
  }
}


void GameControl::alternateTurn(){
  //This function is used to alternate player turn
  if(whoseTurn == 'W')
    {
      whoseTurn = 'B';
    }
  else
    {
      whoseTurn = 'W';
    }
}


int GameControl::playerAI(string aComputer, char aicolour){
  if(aComputer.substr(8,1) == "1"){
     aiplayer = new BotLvl1(aicolour);
     return 1;
  }
  else if(aComputer.substr(8,1) == "2"){
     aiplayer = new BotLvl2(aicolour);
     return 2;
  }
  else if (aComputer.substr(8,1) == "3"){
     aiplayer = new BotLvl3(aicolour);
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


int GameControl::twoPlayerAI(string aComputer, string aComputer2){
  if(aComputer.substr(8,1) == "1"){
     aiplayer = new BotLvl1('W');
  }
  else if(aComputer.substr(8,1) == "2"){
     aiplayer = new BotLvl2('W');
  }
  else if (aComputer.substr(8,1) == "3"){
     aiplayer = new BotLvl3('W');
  }
  else if (aComputer.substr(8,1) == "4"){
  }
  else {
    cout << "invalid computer level" << endl;
    return -1;
  }
  if(aComputer2.substr(8,1) == "1"){
     aiplayer2 = new BotLvl1('B');
  }
  else if(aComputer2.substr(8,1) == "2"){
     aiplayer2 = new BotLvl2('B');
  }
  else if (aComputer2.substr(8,1) == "3"){
     aiplayer2 = new BotLvl3('B');
  }
  else if (aComputer2.substr(8,1) == "4"){
  }
  else {
    cout << "invalid computer level" << endl;
    return -1;
  }
  return 1;
}


void GameControl::startAIGame(){

  if(customBoard == false){
    initBoard();
    whoseTurn = 'W';
  }
  
  resign = false;

  do{
    cout<<*td;
	if(theBoard.isInCheck(whoseTurn)){ 
    notifyInfoMsgChange(whoseTurn == 'W' ? "White is in Check!" : "Black is in Check!");
  }
  else {
    notifyInfoMsgChange("");
  }
 
  	if (whoseTurn == 'W'){
    	Move cpuNextMove = aiplayer->getMove(theBoard);
      executeMove(cpuNextMove);
	    alternateTurn();
	
  	}
  	else if (whoseTurn == 'B'){
   	Move cpuNextMove = aiplayer2->getMove(theBoard);
   	executeMove(cpuNextMove); 
  	alternateTurn();
    }
  } while (!(isGameOver()));

}


void GameControl::printScore(){
  //This function prints the score
  int i1 = whiteScoreCount;
  int i2 = blackScoreCount;
  cout << "Final Score:" << endl;
  cout << "White: " << i1 << endl;
  cout << "Black: "<< i2 << endl;
}


void GameControl::startGame(int player1, int player2){
  if(customBoard == false){
    initBoard();
    whoseTurn = 'W';
  }
  
  resign = false;

  do{
    cout<<*td;
    cout << whoseTurn << " to play!" << endl;
  if(theBoard.isInCheck(whoseTurn)){ 
    notifyInfoMsgChange(whoseTurn == 'W' ? "White is in Check!" : "Black is in Check!");
  }
  else {
    notifyInfoMsgChange("");
  }
 
  	if (whoseTurn == 'W'){
  	  getNextMove(player1);
  	}
  	else if (whoseTurn == 'B'){
  	  getNextMove(player2);
    }
  } while (!(isGameOver()));
}




bool GameControl::isGameOver() {
  //objective : check all pieces that have legal move
  if(resign){
    cout << *td;
    resetBoard();
    return true;
  }

  int allLegalMove = 0;
  vector<ChessPiece *> vcp = theBoard.getAllPiecesByColour(whoseTurn);
  for (unsigned int i = 0; i < vcp.size() ; ++i){
    vector<Move> vofm = vcp[i]->getPossibleMoves(theBoard);
    for (unsigned int j = 0; j < vofm.size() ; ++j){
      if(theBoard.isLegalMove(vofm[j])){
	allLegalMove++;
      }
    }    
  }
  if(allLegalMove == 0){
    //is in check?
    //if yes checkmate, alt , if W? white++ else black++;
    //else stalmate ;
    if(theBoard.isInCheck(whoseTurn)){
      if(whoseTurn == 'W'){
        notifyInfoMsgChange("CheckMate! Black Wins!");
	     ++blackScoreCount;
      }
      else{
        notifyInfoMsgChange("CheckMate! White Wins!");
	     ++whiteScoreCount;
      }
    }
    else{
      notifyInfoMsgChange("StaleMate!");
    }
    resetBoard();
    

    return true;
  }
  else{
    return false;
  }
}


void GameControl::getNextMove(int player){

  if(player == 0){ getHumanMove(whoseTurn); }

  else { 
    Move cpuNextMove = aiplayer->getMove(theBoard);
    executeMove(cpuNextMove); 
  }

  alternateTurn();
}


void GameControl::getHumanMove(char whoseTurn) {
    
  bool done = false;

  while(done!= true) {

    cout << "move/resign" << endl;
    	
      string move_string;
   	  getline(cin,move_string);
    	istringstream move_iss(move_string);
   	 string move_command;
   	 int count = 0;
   	 vector<string> listOfCommand;

    while (move_iss >> move_command){
      listOfCommand.push_back(move_command);
      ++count;
    }

    if (count == 0) continue;

    if(listOfCommand[0] == "move") {

      if (count != 3 && count != 4) {
        cout << "Invalid move command, unmatching argument count" << endl;
        continue;
      }
      if (listOfCommand[1][0] < 'A' || (listOfCommand[1][0] > 'Z' && listOfCommand[1][0] < 'a') || listOfCommand[1][0] > 'z') {
        cout << "Invalid move command, source position not valid" << endl;
        continue;
      }
      if (listOfCommand[1][1] < '0' || listOfCommand[1][1] > '9') {
        cout << "Invalid move command, source position not valid" << endl;
        continue;
      }
      if (listOfCommand[2][0] < 'A' || (listOfCommand[2][0] > 'Z' && listOfCommand[2][0] < 'a') || listOfCommand[2][0] > 'z') {
        cout << "Invalid move command, destination position not valid" << endl;
        continue;
      }
      if (listOfCommand[2][1] < '0' || listOfCommand[2][1] > '9') {
        cout << "Invalid move command, destination position not valid" << endl;
        continue;
      }

      vector<int> vtor = posntran(listOfCommand[1]);
      vector<int> vtor2 = posntran(listOfCommand[2]);
      Posn posn1 = Posn(vtor[0], vtor[1]);
      Posn posn2 = Posn (vtor2[0], vtor2[1]);
      ChessPiece* cp = theBoard.getPieceByPosn(posn1);

      if (count == 4 && cp->getPieceType() == 'P') { // Pawn trying to promote
        if (posn2.getRow() != 0 && posn2.getRow() != 7) { // Destination not at end of board
          cout << "Invalid Promotion" << endl;
          continue;
        }
        if (listOfCommand[3] != "R" && listOfCommand[3] != "N" && listOfCommand[3] != "B" && listOfCommand[3] != "Q") { // Invalid Promotion char
          cout << "Invalid Promotion" << endl;
          continue;
        }
      }
      else if (count == 4 && cp->getPieceType() != 'P') { // Non-Pawn trying to promote
        cout << "Invalid Promotion" << endl;
        continue;
      }
      else if (count == 3 && cp->getPieceType() == 'P' && (posn2.getRow() == 0 || posn2.getRow() == 7)) { // Pawn with a destination at the end of the board. Does not specify Promotion
        cout << "Invalid move command, no promotion specified" << endl;
        continue;
      }

      if (cp == nullptr) {
        cout<<"invalid move, piece is not found"<<endl;
        continue;
      }

      if (cp->getColour() != whoseTurn) {
        cout << "invalid move, cannot move opponent's chess piece" << endl;
        continue;
      }
	
  	vector<Move> vofm = cp->getPossibleMoves(theBoard);	
  	for(unsigned int i = 0 ; i < vofm.size(); ++i){
  		if( vofm[i].getDestination() == posn2 ){
        if (count == 4) {
          done = executeMove(vofm[i], listOfCommand[3][0]);
        }
  			else done = executeMove(vofm[i]);
  			break;
  		}
  	}
  }


  else if(listOfCommand[0] == "resign"){
	cout << whoseTurn << endl;
     if(whoseTurn == 'W'){
        notifyInfoMsgChange("Black Wins!");
	     ++blackScoreCount;
      }
      else{
        notifyInfoMsgChange("White Wins!");
	     ++whiteScoreCount;
      }
     resign = true;
	break;
  }


  else{
    cout << "invalid move command" << endl;
    done = false;
    cout << *td;
  }
  }
}



void GameControl::resetBoard(){
  //intake ChessPiece*
  for(unsigned int i = 0; i<8; ++i){
    for(unsigned int j=0; j<8; ++j){
      Posn aposn = Posn(i,j);
      ChessPiece* acp = theBoard.getPieceByPosn(aposn);
      removePiece(acp);
    }
  }
  customBoard = false;
}


bool GameControl::checkSetupCondition(){
  
  // Only one king for black and white
  // No pawns on first and last row
  //bool cond2 = true;
  vector<ChessPiece*> vcp1 = theBoard.getAllPiecesByColour('W');
  vector<ChessPiece*> vcp2 = theBoard.getAllPiecesByColour('B');
  int wk = 0;
  int bk = 0;
  
  for(unsigned int i = 0; i < vcp1.size(); ++i){
    if(vcp1[i]->getPieceType() == 'K'){
      wk++;

    }
    else if(vcp1[i]->getPieceType() == 'P'){
      Posn aposn = vcp1[i]->getPosition();
	if (aposn.getRow() == 0 || aposn.getRow() == 7) return false;
    }
  }
  for(unsigned int j = 0; j < vcp2.size(); ++j){
    if(vcp2[j]->getPieceType() == 'K'){
      bk++;
    }
    else if(vcp2[j]->getPieceType() == 'P'){
      Posn aposn= vcp2[j]->getPosition();

	if (aposn.getRow() == 0 || aposn.getRow() == 7) return false;

    }
  }

  if(wk != 1 || bk != 1){
	return false;
  }


	if (theBoard.isInCheck('B') || theBoard.isInCheck('W')) return false;

	return true;
}




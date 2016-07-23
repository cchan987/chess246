#include <vector>
#include <iostream>
#include <sstream>


using namespace std;

//================================================
//.h file
void gameOn();
vector<vector<char> > initBoard();
vector<vector<char> > setupBoard(vector<vector<char> > a);
void printBoard(vector<vector<char> > b);
vector<int> strToVector(string s);

//================================================

int main(){
  //game on
  gameOn();

}

//================================================
void gameOn(){
 

  cout << "Please input: game, setup" << endl;
  //board initalized
  vector<vector<char> > board;
  board = initBoard();
  printBoard(board);
    
  //readin command
  string user_input;
  getline(cin,user_input);
  istringstream iss(user_input);
  string s;
  //read first command
  getline(iss,s,' ');
  if(s == "game"){
    cout<<"enter game mode"<<endl;
    //gameMode();
   }
  else if (s == "setup"){
    //setupBoard();
    cout<<"please setup the board"<<endl;
    board = setupBoard(board);
    cout << "===============FINAL BOARD======================="<<endl;
    printBoard(board);
  }
  else{
    cout << "invalid input" <<endl;
  }
  
}
//================================================



vector<vector<char> > initBoard(){
  
  int iRow = 8;
  int iCol = 8;
  int playerNum = 2;
  string whoseTurn = "white";
  
  //define a vector of vectors
  vector<vector<char> >board;

  //initalize empty board
  for(int i = 0; i < iRow; i++){
    vector<char>temp;
    for(int j = 0; j < iCol; j++){
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
  for(int i = 0; i<8; ++i){ board[6][i] = 'p'; }
  board[7][0] = 'r';
  board[7][1] = 'n';
  board[7][2] = 'b';
  board[7][3] = 'k';
  board[7][4] = 'q';
  board[7][5] = 'b';
  board[7][6] = 'n';
  board[7][7] = 'r';
  for(int i = 0; i<8; ++i){ board[1][i] = 'P';}
  board[0][0] = 'R';
  board[0][1] = 'N';
  board[0][2] = 'B';
  board[0][3] = 'K';
  board[0][4] = 'Q';
  board[0][5] = 'B';
  board[0][6] = 'N';
  board[0][7] = 'R';




  return board;
}

//================================================

//vector<int> strToVector(string s){
//  vector<int> posn;
//  int x,y;
  
//  string x0 = s.substr(0,1);
//  string y0 = s.substr(1,1);

//  stringstream x1(x0);
//  stringstream y1(y0);
  
//  x1 >> x;
//  y1 >> y;
  
//  posn.push_back(x);
//  posn.push_back(y);
//  return posn;
//}


//================================================


vector<vector<char> > setupBoard(vector<vector<char> > aBoard){

  
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
      aBoard[y0-1][x0-1] = chessPiece;
      printBoard(aBoard);
      break;
      
    case '-':
      cin >> x >> y;
      x0 = x - 48;
      y0 = y - 48;
      aBoard[y0-1][x0-1] = '-';
      printBoard(aBoard);
      break;
      
    case 'q':
      done = true;
      break;
      
    }
  }

  


  
  return aBoard;

}


//===============================================

void printBoard(vector<vector<char> > board){
  
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


































  



    // while(getline(iss,s,' ')){
    //  cout << s;
    //}





 //display all elements to the user
  // for (int i=0; i<board.size(); i++){
  //  for (int j=0; j<board[i].size(); j++){
  //    cout << board[i][j];
  //  }
  //  cout << endl;
  //}
  //display edges

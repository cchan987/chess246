#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;




void switchOn();
void menu();
void menu2();
void selectGameMode(string);





int main(){

  switchOn();
  return 0;
}


void switchOn(){
  menu2();
}


void menu(){

 cout << "command: game _ _ / setup / score / quit" << endl;

   bool exit = false;
   
 while (exit != true){
 
  string menu_string;
  getline(cin,menu_string);
  istringstream menu_iss(menu_string);
  string menu_command;
  
  int command_count = 0;

  
  while (menu_iss >> menu_command && command_count < 1){

    //  getline(menu_iss, menu_command, ' ');
    if(menu_command == "game"){
      ++command_count;
      cout << "entered game mode" << endl;
      selectGameMode(menu_string);
    }
    else if (menu_command == "setup"){
      ++command_count;
      cout << "entered setup mode" << endl;
    }
    else if (menu_command == "score"){
      ++command_count;
      cout << "print score" << endl;
    }
    else if (menu_command == "quit"){
      ++command_count;
      cout << "exit game" << endl;
      exit = true;
    }  
    else{
      cout << "invalid input" << endl;
    }
  }

  
 }

 

 
}


void selectGameMode(string s){
 
  istringstream gameMode_iss(s);
  bool exit= false;
  string temp;
  int number_of_player = 2;
  int count = 0;
  vector<string> listOfPlayer;
   
   while(gameMode_iss >> temp){
     listOfPlayer.push_back(temp);
     ++count;
   }

   //do something
   for(int i = 1 ; i < listOfPlayer.size(); i++){
   cout << listOfPlayer[i] << endl;
   }
   
}




//void selectGameMode(istringstream s1_s2){
//  istringstream gameMode_command;
//  string firstPlayer,secondPlayer;
//  bool exit = false;
//  while (exit != true){
//    getline(gameMode_command, firstPlayer,' ');
//    getline(gameMode_command, firstPlayer,' ');
    
//    if(firstPlayer && secondPlayer == "human"){
//      cout << "pvp" << endl;
//    }
//    else if(firstPlayer && secondPlayer == "computer"){
//     cout << "cvc" << endl;
//    }
//    else if ((firstPlayer == "human" && secondPlayer == "computer")||(secondPlayer == "human" && firstPlayer == "computer")){
//      cout << "pvc" << endl;
//   }
//   else{
//    cout<< "invalid player types" << endl;
//     exit = true;
//  }
// }
//}




void menu2(){
  cout << "command: game _ _ / setup / score / quit" << endl;
  bool exit = false;
  
  while (exit != true){
  
  string menu_string;
  getline(cin,menu_string);
  istringstream menu_iss(menu_string);
  string menu_command;
  int count = 0;
  vector<string> listOfCommand;

  bool back = false;


  string firstPlayer;
  string secondPlayer;
  
  //one time command
   while(menu_iss >> menu_command){
     listOfCommand.push_back(menu_command);
     ++count;
   }

   while(back!=true){
   if (listOfCommand.size() == 0){
     cout << "Please Enter Command" << endl;
     back = true;
   }

   
   if (listOfCommand[0] == "game"){
     if (listOfCommand.size() != 3){
       cout << "Invalid Game Command Input; Please try again" << endl;
       back = true;
     }
     else{
       firstPlayer = listOfCommand[1];
       secondPlayer = listOfCommand[2];
       if(firstPlayer == "human" && secondPlayer == "human"){
	 cout << "pvp" << endl;
       }
       else if(firstPlayer == "computer" && secondPlayer == "computer"){
	 cout << "cvc" << endl;
       }
       else if ((firstPlayer == "human" && secondPlayer == "computer")||(secondPlayer == "human" && firstPlayer == "computer")){
	 cout << "pvc" << endl;
       }
       else{
	 cout<< "Invalid Player Input" << endl;
       }
       back = true;
     } 	   
   }

   
   else if (listOfCommand[0] == "setup"){       
     if (listOfCommand.size() != 1){
       cout << "Invalid Setup Command input" << endl;
     }
     else{
       cout << "enter setup mode" << endl;
     }
      back = true;
   }

   
   else if (listOfCommand[0] == "quit"){
    if (listOfCommand.size() != 1){
       cout << "Invalid Quit Command input" << endl;
       back = true;
     }
     else{
       cout << "Exit game; Thank you for playing" << endl;
       back = true;
       exit = true;
     }
   }
   else{
     cout<< "Invalid Command Input Please try again" << endl;
     back = true;
   }
   }

   back = false;
  }
}

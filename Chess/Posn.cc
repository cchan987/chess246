
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

#include <Board.h>

using namespace std;

Posn::Posn(int x, int y)
{
  //ctor
  row = x;
  col = y;
}

int Posn::getRow(){
	return row;
}


int Posn::getCol(){
	return col;
}


void Posn::setRow(int x){
	row = x;
}


void Posn::setCol(int y){
	col = y;
}
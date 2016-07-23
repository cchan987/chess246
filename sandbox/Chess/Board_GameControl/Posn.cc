
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

Posn::~Posn()
{
	delete row;
	delete col;
}  


Posn::getRow(){
	return row;
}


Posn::getCol(){
	return col;
}


Posn::setRow(int x){
	row = x;
}


Posn::setCol(int y){
	col = y;
}
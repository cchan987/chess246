#include "gamecontrol.h"
#include "window.h"
#include <iostream>

int main(){
	Xwindow w;
	GameControl game1(w);
	game1.switchOn();
	//std::cout << "finished switchon";
	return 0;
}

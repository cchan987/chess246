#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include <string>
#include "observer.h"

class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay;
  const int gridSize;
  std::string infoMsg = "";
 public:
  TextDisplay(int n);
  void notifyBoard(ChessPiece *cp, Posn dst) override; 
  void notifyInfoMsg(std::string msg) override;
  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

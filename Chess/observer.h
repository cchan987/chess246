#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class ChessPiece;
class Posn;

class Observer {
 public:
  virtual void notifyBoard(ChessPiece *cp, Posn dst) = 0; 
  virtual void notifyInfoMsg(std::string msg) = 0;
  char getCellColour(int r, int c);
  virtual ~Observer() = default;
};
#endif

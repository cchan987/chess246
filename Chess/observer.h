#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class ChessPiece;
class Posn;

class Observer {
 public:
  virtual void notifyBoard(ChessPiece &cpm, Posn src, Posn dst) = 0; 
  virtual void notifyInfoMsg(String msg) = 0;
  char getCellColour(int r, int c);
  virtual ~Observer() = default;
};
#endif

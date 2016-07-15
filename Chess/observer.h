#ifndef _OBSERVER_H_
#define _OBSERVER_H_
class Cell;

enum class SubscriptionType { All, SwitchOnly };

class Observer {
 public:
  virtual void notify(Cell &c) = 0;  // c is the Cell that called the notify method
  virtual SubscriptionType subType() = 0;
  virtual ~Observer() = default;
};
#endif

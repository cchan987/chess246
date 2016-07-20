#ifndef _POSN_H_
#define _POSN_H_

class Posn {
	int column;
	int row;
public:
	Posn(int column, int row);
	int getColumn() const;
	int getRow() const;
};

#endif
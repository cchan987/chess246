#ifndef __POSN_H__
#define __POSN_H__

class Posn
{	

public: 
	Posn(int x, int y);
	int getCol();
	int getRow();
	void setCol(int x);
	void setRow(int y);

private:
	int col;
	int row;
	
};


#endif

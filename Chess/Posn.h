#ifndef __POSN_H__
#define __POSN_H__

class Posn
{	

public: 
	Posn(int, int);
	int getCol();
	int getRow();
	void setCol(int );
	void setRow(int );

private:
	int col;
	int row;
	
};


#endif

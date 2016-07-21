#ifndef __POSN_H__
#define __POSN_H__



class Posn
{	

public: 
	Posn(int x, int y);
	int getCol() const;
	int getRow() const;
	void setCol(int );
	void setRow(int );

private:
	int col;
	int row;
	
};


#endif

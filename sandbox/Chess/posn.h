#ifndef __POSN_H__
#define __POSN_H__

class Posn
{	

public: 
	Posn(int x, int y);
	int getCol() const;
	int getRow() const;
	void setCol(int x);
	void setRow(int y);
	bool operator==(const Posn& other);

private:
	int col;
	int row;
	
};


#endif

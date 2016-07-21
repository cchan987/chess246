
#include <chesspiece.h>
#include <Move.h>
#include <Pawn.h>

void Pawn::setMoved() {
	hasBeenMoved = true;
}

bool Pawn::hasBeenMoved() {
	return hasBeenMoved;
}

char Pawn::getPieceType() {
	return ‘P’;
}


vector<Move> Pawn::getPossibleMoves(){
	vector<Move> PossibleMoves;
	int row = location.getRow();
	int col = location.getCol();	

	if (colour == ‘W’){
		if(row-1 > -1 && col+1 < 7){
		PossibleMoves.emplace_back(this, Posn(row-1, col+1));
		}
		if(row+1 < 8 && col+1 < 7){
		PossibleMoves.emplace_back(this, Posn(row+1, col+1));
		}
		if(col+1 < 7){
		PossibleMoves.emplace_back(this, Posn(row, col+1));
		}
		if(hasBeenMoved == false && col+2 < 7){
		PossibleMoves.emplace_back(this, Posn(row, col+2));
		}
	}


		if (colour == ‘B’){
		if(row-1 > -1 && col-1 > 0){
		PossibleMoves.emplace_back(this, Posn(row-1, col-1));
		}
		if(row+1 < 8 && col-1 > 0){
		PossibleMoves.emplace_back(this, Posn(row+1, col-1));
		}
		if(col-1 > 0){
		PossibleMoves.emplace_back(this, Posn(row, col-1));
		}
		if(hasBeenMoved == false && col-2 > 0){
		PossibleMoves.emplace_back(this, Posn(row, col-2));
		}
	}

}
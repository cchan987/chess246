#include "botLvl3.h"
#include "board.h"
#include "chesspiece.h"
#include <map>

using namespace std;

BotLvl3::~BotLvl3(){

}
BotLvl3::BotLvl3(char colour){allegiance = colour;}

bool BotLvl3::isColourThreateningSquare(char colour, Posn p, Board &b) {
	vector<Move> opponentPossibleMoves = b.getAllPossibleMovesByColour(colour);
	for (unsigned int i = 0; i < opponentPossibleMoves.size(); ++i) {
		if (opponentPossibleMoves[i].getDestination() == p) {
			return true;
		}
	}
	return false;
}

bool isPosnMember(vector<Posn> v, Posn p) {
	for (unsigned int i = 0; i < v.size(); i++) {
		if (v[i] == p) {
			return true;
		}
	}
	return false;
}

vector<ChessPiece *> BotLvl3::getMyThreatenedPieces(Board &b) {
	char opponent = (allegiance == 'W')?'B':'W';
	vector<Move> opponentPossibleMoves = b.getAllPossibleMovesByColour(opponent);
	vector<Posn> threats; // Need to fix this
	vector<ChessPiece *> myThreatenedPieces;

	for (unsigned int i = 0; i < opponentPossibleMoves.size(); ++i) {
		Move currentMove = opponentPossibleMoves[i];
		if (currentMove.getIsCapturingMove()) {
			if (isPosnMember(threats, currentMove.getDestination()) == false) {
				threats.emplace_back(currentMove.getDestination());
				myThreatenedPieces.emplace_back(b.getPieceByPosn(currentMove.getDestination()));
			}
		}
	}
	return myThreatenedPieces;
}

vector<Move> BotLvl3::getCapturingandCheckingMoves(Board &b) {
	vector<Move> availableMoves = b.getAllPossibleMovesByColour(allegiance);
	vector<Move> filteredMoves;
	for (unsigned int i = 0; i < availableMoves.size(); ++i) {
		if (b.isCheckingMove(availableMoves[i]) || availableMoves[i].getIsCapturingMove()) {
			filteredMoves.emplace_back(availableMoves[i]);
		}
	}
	return filteredMoves;
}


/*
vector<ChessPiece *> BotLvl3::hostilePieces(Board &b) {
	char opponent = (allegiance == 'W')?'B':'W';
	vector<ChessPiece *> opponentPieces = getAllPiecesByColour(opponent);
	for (unsigned int i = 0; i < opponentPieces.size(); ++i) {

	}
}*/

vector<Move> BotLvl3::getSalvagingMoves(Board &b) {
	char opponent = (allegiance == 'W')?'B':'W';
	// Move out of capture
	vector<Move> mySalvagingMoves;
	vector<ChessPiece *> myThreatenedPieces = getMyThreatenedPieces(b);
	for (unsigned int i = 0; i < myThreatenedPieces.size(); ++i) { 
		vector<Move> myMoves = myThreatenedPieces[i]->getPossibleMoves(b);
		for (unsigned int i = 0; i < myMoves.size(); ++i) {
			if (!(isColourThreateningSquare(opponent, myMoves[i].getDestination(), b))) {
				mySalvagingMoves.emplace_back(myMoves[i]);
			}
		}
	}
	return mySalvagingMoves;
}

Move BotLvl3::getMove(Board &b) {

	vector<Move> mySalvagingMoves = getSalvagingMoves(b);
	if (mySalvagingMoves.size() > 0){
		int randNum = rand() % mySalvagingMoves.size();
		return mySalvagingMoves[randNum];		
	}

	vector<Move> myCapturingAndCheckingMoves = getCapturingandCheckingMoves(b);
	if (myCapturingAndCheckingMoves.size() > 0){
		int randNum = rand() % myCapturingAndCheckingMoves.size();
		return myCapturingAndCheckingMoves[randNum];		
	}	

	cout << "getting moves for ai colour: " << allegiance << endl;
	vector<Move> otherMoves = b.getAllPossibleMovesByColour(allegiance);
	cout << "b4 rand moves: " << otherMoves.size() << endl;
	int randNum = rand() % otherMoves.size();
	cout << "after rand moves: " << randNum << endl;
	return otherMoves[randNum];		
}

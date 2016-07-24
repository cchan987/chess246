#include "botLvl3.h"
#include "board.h"
#include "chesspiece.h"
#include <map>

using namespace std;

BotLvl3::~BotLvl3(){

}

bool BotLvl3::isSquareThreatened(Posn p) {
	char opponent = (allegiance == "W")?"B":"W";
	vector<Move> opponentPossibleMoves = getAllPossibleMovesByColour(opponent);
	for (unsigned int i = 0; i < opponentPossibleMoves.size(); ++i) {
		if (opponentPossibleMoves[i].getDestination() == p) {
			return true;
		}
	}
	return false;
}

vector<ChessPiece *> BotLvl3::getMyThreatenedPieces(Board &b) {
	char opponent = (allegiance == "W")?"B":"W";
	vector<Move> opponentPossibleMoves = getAllPossibleMovesByColour(opponent);
	map<Posn, int> threats;
	vector<ChessPiece *> myThreatenedPieces;

	for (unsigned int i = 0; i < opponentPossibleMoves.size(); ++i) {
		Move currentMove = opponentPossibleMoves[i];
		if (currentMove.getIsCapturingMove()) {
			if (!(threats.count(currentMove.getDestination()))) {
				threats[currentMove.getDestination()];
				myThreatenedPieces.emplace_back(b.getPieceByPosn(currentMove.getDestination()));
			}
		}
	}
	return myThreatenedPieces;
}

vector<Move> BotLvl3::getCapturingandCheckingMoves(Board &b) {
	vector<Move> availableMoves = b.getAllLegalMovesByColour(allegiance);
	vector<Move> filteredMoves;
	for (int i = 0; i < availableMoves.size(); ++i) {
		if (b.isCheckingMove(availableMoves[i]) || b.isCapturingMove(availableMoves[i])) {
			filteredMoves.emplace_back(availableMoves[i]);
		}
	}
	return filteredMoves;
}

vector<Move> BotLvl3::getSalvagingMoves(Board &b) {
	vector<Move> mySalvagingMoves;
	vector<ChessPiece *> myThreatenedPieces = getMyThreatenedPieces(b);
	for (unsigned int i = 0; i < myThreatenedPieces.size(); ++i) {
		Posn location = myThreatenedPieces.getLocation();
		vector <Move> myMoves = myThreatenedPieces.getPossibleMoves();
		for (unsigned int i = 0; i < myMoves.size(); ++i) {
			if (!(isSquareThreatened(myMoves[i].getDestination()))) {
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

	vector<Move> otherMoves = b.getAllLegalMovesByColour(allegiance);
	int randNum = rand() % otherMoves.size();
	return otherMoves[randNum];		
}

#include "botLvl3.h"
#include "board.h"
#include "chesspiece.h"

using namespace std;

vector<ChessPiece *> BotLvl3::getMyThreatenedPieces(Board &b) {

}

vector<Posn> BotLvl3::getSquaresThreatenedByOpponent(Board &b) {
	char opponent = (allegiance == "W")?"B":"W";
	vector<Move> opponentPossibleMoves = getAllPossibleMovesByColour(opponent);
	
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



//Does the piece that is being moved end up in a position that allows it to be captured
bool BotLvl3::isMoveSafe(Move m) {

}

Move BotLvl3::getMove(Board &b) {

}
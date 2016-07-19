#include "botLvl1.h"
#include "move.h"
#include "board.h"

using namespace std;

vector<move> BotLvl1::getAllLegalMovesByColour(char colour, Board &b) {
	vector<move> v;
	for (int i = 0; i < b.theBoard.size(); i++) {
		for (int j = 0; j < b.theBoard[i]; j++) {
			ChessPiece *current_piece = b.theBoard[i][j];
			if (current_piece) {
				vector<move> currentPieceMoves = 
				v.insert();
			}
		}
	}
}

move BotLvl1::getMove(Board &b) {
	vector<move> legal_moves = getAllLegalMovesByColour(allegiance, b);
	int randNum = rand() % legal_moves.size();
	return legal_moves[randNum];
}
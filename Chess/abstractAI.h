class AbstractAI {
	char allegiance;
	vector getAllLegalMovesByColour(char colour);
public:
	virtual void getMove(Board &b) = 0;
};
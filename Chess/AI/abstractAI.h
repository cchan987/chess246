class AbstractAI {
	char allegiance;
public:
	virtual void getMove(Board &b) = 0;
};
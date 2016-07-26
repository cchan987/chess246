#include <vector>

class AbstractAI {
	char allegiance;
	std::vector getAllLegalMovesByColour(char colour);
public:
	virtual ~AbstractAI();
	virtual void getMove(Board &b) = 0;
};
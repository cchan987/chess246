#include "observer.h"

char Observer::getCellColour(int r, int c) {
	if (r % 2 == 0) {
		if (c % 2 == 0) {
			return 'W';
		}
		else {
			return 'B';
		}
	}
	else {
		if (c % 2 == 0) {
			return 'B';
		}
		else {
			return 'W';
		}				
	}
}
CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -g
EXEC = chess
OBJECTS = main.o textdisplay.o graphicsdisplay.o bishop.o board.o chesspiece.o gamecontrol.o king.o knight.o move.o observer.o pawn.o posn.o queen.o rook.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

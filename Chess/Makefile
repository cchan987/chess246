CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = chess
OBJECTS = main.o textdisplay.o bishop.o Board.o chesspiece.o GameControl.o king.o knight.o move.o observer.o Pawn.o Posn.o queen.o rook.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

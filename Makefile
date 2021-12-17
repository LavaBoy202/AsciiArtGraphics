CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a4q3
OBJECTS = studio.o asciiart.o blank.o subject.o addgraphics.o window.o addtext.o observer.o main.o filledbox.o movingbox.o blinkingbox.o maskbox.o decorator.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}i

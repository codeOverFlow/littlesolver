.SUFFIXES: clean
.PHONY:
OPTION = -std=c++11
OPTI = -O2 -Os # pour debugger commenter les valeurs
INCLUDE = -I .
EXECNAME = appli
COMPIL = clang++
DEBUG = #-g # pour debugger decommenter les valeurs

all: main.o assignproblem.o backtracking.o domain.o node.o queens.o localsearch.o
	${COMPIL} ${OPTION} ${OPTI} ${INCLUDE} main.o assignproblem.o backtracking.o domain.o node.o queens.o  localsearch.o -o ${EXECNAME}
	rm *.o

main.o:
	${COMPIL} -c ${OPTION} ${OPTI} main.cpp

assignproblem.o:
	${COMPIL} -c ${OPTION} ${OPTI} assignproblem.cpp

backtracking.o:
	${COMPIL} -c ${OPTION} ${OPTI} backtracking.cpp

domain.o:
	${COMPIL} -c ${OPTION} ${OPTI} domain.cpp

node.o:
	${COMPIL} -c ${OPTION} ${OPTI} node.cpp

queens.o:
	${COMPIL} -c ${OPTION} ${OPTI} queens.cpp

localsearch.o:
	${COMPIL} -c ${OPTION} ${OPTI} localsearch.cpp


clean:
	rm *.o

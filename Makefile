.SUFFIXES: clear
.PHONY:
OPTION = -std=c++11
OPTI = -O2 -Os -s # pour debugger commenter les valeurs
INCLUDE = -I .
EXECNAME = appli
DEBUG =# -g # pour debugger decommenter les valeurs

all: main.o assignproblem.o backtracking.o domain.o node.o
	g++ ${OPTION} ${OPTI} ${INCLUDE} main.o assignproblem.o backtracking.o domain.o node.o -o ${EXECNAME}

main.o:
	g++ -c ${OPTION} ${OPTI} main.cpp

assignproblem.o:
	g++ -c ${OPTION} ${OPTI} assignproblem.cpp

backtracking.o:
	g++ -c ${OPTION} ${OPTI} backtracking.cpp

domain.o:
	g++ -c ${OPTION} ${OPTI} domain.cpp

node.o:
	g++ -c ${OPTION} ${OPTI} node.cpp

clear:
	rm *.o

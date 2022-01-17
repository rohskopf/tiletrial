.SUFFIXES: .h .cpp
#-----------------------------------------------
# Makefile for TileTrial
# Please modify the variables properly.
# Recommend to use gcc >= 4.8 with openMPI >= 1.8
#-----------------------------------------------

CXX = mpicxx
CXXFLAGS = -std=c++11 -Wno-write-strings

INCLUDE = 

CXXL =
LDFLAGS = 

LAPACK =
LIBS = 

#-----------------------------------------------
# General rules 
#-----------------------------------------------

.cpp.o:
	${CXX} ${CXXFLAGS} ${INCLUDE} -c $<

PROG = tiletrial

CXXSRC= tt.cpp main.cpp container.cpp memory.cpp functions.cpp timer.cpp

OBJS= ${CXXSRC:.cpp=.o}

default: tiletrial

all: ${PROG}

tiletrial: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LIBS}

clean:
	rm -f ${OBJS}

.PHONY: clean

depend:
	gcc -MM *.cpp > .depend

-include .depend

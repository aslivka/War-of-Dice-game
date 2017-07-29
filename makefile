# * * * *  * ******************************************************************
# Author     : Amir Rasekh
# Date       : 7/23/17
# Description: Makefile for Group Project
# Note	     : Parts of this makefile have been adopted from the sample makefile
#			   posted on canvas.
# * * * *  * ** ***************************************************************/

# Project Name
PROJ = GroupProject

# Source Files
SRC  = play_game.cpp
SRC += RPSGame.cpp
SRC += Tool.cpp
SRC += Rock.cpp
SRC += Paper.cpp
SRC += Scissors.cpp

# Objects 
OBJ = play_game.o
OBJ += RPSGame.o
OBJ += Tool.o
OBJ += Rock.o
OBJ += Paper.o
OBJ += Scissors.o

# Headers 
HEADERS = RPSGame.hpp
HEADERS += Tool.hpp
HEADERS += Rock.hpp
HEADERS += Paper.hpp
HEADERS += Scissors.hpp

# target: dependencies
#	rules to build 
default: $(OBJ)
	$(CXX) $(OBJ) -o $(PROJ)

play_game.o: play_game.cpp
	$(CXX) $(CXXFLAGS) -c play_game.cpp

RPSGame.o: RPSGame.cpp RPSGame.hpp
	$(CXX) $(CXXFLAGS) -c RPSGame.cpp

Tool.o: Tool.cpp Tool.hpp
	$(CXX) $(CXXFLAGS) -c Tool.cpp

Rock.o: Rock.cpp Rock.hpp
	$(CXX) $(CXXFLAGS) -c Rock.cpp

Paper.o: Paper.cpp Paper.hpp
	$(CXX) $(CXXFLAGS) -c Paper.cpp

Scissors.o: Scissors.cpp Scissors.hpp
	$(CXX) $(CXXFLAGS) -c Scissors.cpp


# The flaw with the following method is that each time even one file is edited, 
# all the files will be compiled again. 
#$(OBJ): $(SRC) $(HEADERS)
#	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

# Compiler
CXX = g++

# Compiler flags 
CXXFLAGS = -Wall
CXXFLAGS += -pedantic-errors 
CXXFLAGS += -std=gnu++11
CXXFLAGS += -g

# Output C++ file
OUTPUT = $(PROJ)

# Valgrind Options
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

# Names of tags that aren't actually files. Without this, if there were ever a
# file in the directory with these names they would never run.
#
# Why? Because Make is checking to see if these files exist. If they already do
# it skips them!
.PHONY: default debug clean zip

# Notice the dependency chain.
#
# Order assuming no files exist:
#     1. Each .o file
#     2. Binary
#     3. Valgrind
debug: $(PROJ)
	valgrind $(VOPT) ./$(PROJ)

zip:
	zip -D $(PROJ)_Rasekh_Amir.zip *.cpp *.hpp makefile

clean: $(CLEAN)
	rm -f *.o $(PROJ)
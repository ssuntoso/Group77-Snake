# Game Title: SNAKE-77
# Group     : 77
# Author    : Kwan, Rafael Matthew Susanto (3035742425)
#             Suntoso, Sean Michael (3035742437)

# This Makefile is a part of the COMP2113 course project SNAKE-77.

# required separated files for SNAKE-77:
# - ./includes/gameplayLogic.cpp
# - ./includes/gameplayLogic.h 
# - ./includes/leaderboard.cpp
# - ./includes/leaderboard.h
# - Makefile

# use `make all` command for compile all
# use `make clean` and then `make all` to reset the game 

CC		:= g++
CFLAGS	:= -pthread -pedantic-errors -std=c++11
target	:= snake	
objs	:= main_snake.o leaderboard.o gameplayLogic.o

INCLUDES_DIR := ./includes

all: $(target)

# run this command multiple time for 
# all .cpp and .h file in includes folder
%.o: $(INCLUDES_DIR)/%.cpp $(INCLUDES_DIR)/%.h
	$(CC) $(CFLAGS) -c $<

# run this command multiple time for 
# all .cpp in main folder 
# and .h file in includes folder
%.o: %.cpp $(wildcard $(INCLUDES_DIR)/*.h)
	$(CC) $(CFLAGS) -c $<

snake: $(objs) 
	$(CC) $(CFLAGS) $^ -o $@

tgz		:= $(wildcard *.tgz)

clean:
	rm -f $(wildcard *.o) $(target) $(tgz) leaderboard.txt

tar:
	tar -czvf $(tgz) *.cpp *.h *.o 

.PHONY: clean tar
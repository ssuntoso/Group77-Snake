CC			    := g++
CFLAGS		  := -pthread -pedantic-errors
CVER		    := -std=c++11
CCFLAGSVER	:= $(CC) $(CFLAGS) $(CVERSION)

main_snake.o: main_snake.cpp
	$(CCFLAGSVER) -c main_snake.cpp

gameplayLogic.o: ./includes/gameplayLogic.cpp
	$(CCFLAGSVER) -c ./includes/gameplayLogic.cpp

leaderboard.o: ./includes/leaderboard.cpp
	$(CCFLAGSVER) -c ./includes/leaderboard.cpp

snake: main_snake.o leaderboard.o gameplayLogic.o 
	$(CCFLAGSVER) main_snake.o leaderboard.o gameplayLogic.o -o snake

clean:
	rm -f *.o snake snake.tgz

tar:
	tar -czvf snake.tgz *.cpp *.h

.PHONY: clean tar

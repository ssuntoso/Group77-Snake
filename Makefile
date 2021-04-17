# use `make all` command for compile all

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
	rm -f $(wildcard *.o) $(target) $(tgz)

tar:
	tar -czvf $(tgz) *.cpp *.h *.o

.PHONY: clean tar
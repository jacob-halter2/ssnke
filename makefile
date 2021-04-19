#snake programa

CC = g++
CFLAGS = -Wall -g

snake: driver.o score.o
	$(CC) $(CFLAGS) -o snake driver.o score.o -lncurses

driver.o: driver.cpp score.o score.h controls.h homeMenu.h gamePlay.h
	$(CC) $(CFLAGS) -c driver.cpp score.o -lncurses

score.o: score.cpp score.h
	$(CC) $(CFLAGS) -c score.cpp

#gamePlay.o: gamePlay.cpp gamePlay.h score.h scores.h drawBoard.h
#   $(CC) $(CFLAGS) -c gamePlay.cpp

clean:
	rm -f *.o out *~

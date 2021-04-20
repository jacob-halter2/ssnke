#snake programa

CC = g++
CFLAGS = -Wall -g

snake: driver.o gamePlay.o score.o snakeBody.o controls.o
	$(CC) $(CFLAGS) -o snake driver.o gamePlay.o score.o snakeBody.o -lncurses

score.o: score.cpp score.h
	$(CC) $(CFLAGS) -c score.cpp

snakeBody.o: snakeBody.cpp snakeBody.h 
	$(CC) $(CFLAGS) -c snakeBody.cpp

controls.o: controls.cpp controls.h
	$(CC) $(CFLAGS) -c controls.cpp -lncurses

gamePlay.o: gamePlay.cpp snakeBody.h controls.h gamePlay.h
	$(CC) $(CLFAGS) -c gamePlay.cpp -lncurses

driver.o: driver.cpp score.h records.h controls.h homeMenu.h gamePlay.h
	$(CC) $(CFLAGS) -c driver.cpp -lncurses

clean:
	rm -f *.o out *~

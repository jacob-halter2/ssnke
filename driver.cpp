#include <iostream>
#include <iomanip>
#include <ncurses.h>

#include "score.h"		//score class
#include "records.h"	//highscore get / set functions
#include "controls.h"	//game controls class
#include "homeMenu.h"	//display for the home menu
#include "gamePlay.h"	//run the game

#define BOARDSIZE 40	//

int main()
{
	//load scores
	Score *scores = new Score[20];
	loadScores(scores);
	
	//load settings 
	//todo: make Controls modificable
	Controls keymap;
	
	//initialize Screen
	initscr();
	noecho();
	cbreak();
	clear();
	keypad(stdscr, TRUE);

	//run menu loop
	char nextAction = 'm';
	char button = ' ';
	int position = 0;
	while(nextAction != 'q' && nextAction != 'Q')
	{	
		printHomeMenu(position, scores, stdscr);
		button = keymap.handleKeypress(getch());
		nextAction = homeCaseSelect(button, position);
		if(nextAction == 's')
		{
			runGame(position, stdscr, BOARDSIZE, keymap);
		}
	}
	//save scores
	
	endwin();
}

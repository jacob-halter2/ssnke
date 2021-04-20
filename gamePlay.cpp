#include <iostream>
#include <ncurses.h>

#include "snakeBody.h"
#include "controls.h"
#include "gamePlay.h"

bool holdGameHostage(bool &gameOver, WINDOW* gameBoard, Controls keymap)
{
    char button = ' ';
    while(1)
    {
    button = keymap.handleKeypress(getch());
    if(button == 'q')
        return true;    //set gameover = true
    else if(button == 'p')
        return false;
    }
}

void runGame(int position, WINDOW *stdscr, int boardSize, Controls keymap)
{
    clear();
    WINDOW* gameBoard = newwin(boardSize, 2*boardSize,10,2);
    //wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');
    //wborder(gameBoard, '|', '|', '-', '-', '+', '+', '+', '+');
    box(gameBoard,0,0);
    refresh();
    wrefresh(gameBoard);
    bool gameOver = false;
    char button = ' ';
    while(!gameOver)
    {
        //do the delay
        //move snake
        button = keymap.handleKeypress(getch());
        if(button == 'q')
            gameOver = true;
        else if(button == 'p')
            gameOver = holdGameHostage(gameOver, gameBoard, keymap);
    }
    //add walls

    //add snake
    //add food


    //showScore
    //showControls
    delwin(gameBoard);
}

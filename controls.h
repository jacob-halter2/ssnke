#pragma once
#include <ncurses.h>

class Controls
{
public:
	Controls();	
	//setters
	
	//getters
	int getUp()		{ return up;	} 
	int getDown()	{ return down;	}
	int getLeft()	{ return left;	}
	int getRight()	{ return right; }
	int getPause()	{ return pause; }
	int getEnter()	{ return enter; }
	int getQuit()	{ return quit;	}	
	//read/write scheme from/to file
	
	//methods
	char handleKeypress(int ch);

private:
	int    up;
	int  down;
	int  left;
	int right;
	int pause;
	int enter;
	int  quit;
}; 


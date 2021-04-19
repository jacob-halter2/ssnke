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

Controls::Controls()
{
	//get controls from file
	//readFromFile
	up		= 'w';
	down	= 's';
	left	= 'a';
	right	= 'd';
	pause	= 'p';
	enter	= 'f';
	quit	= 'q';
}

char Controls::handleKeypress(int receivedFromGetch)
{
	
	int ch = receivedFromGetch;
	if(ch == getUp())
		return 'u';
	/*switch(ch)
	{
		case this->getUp():
			return 'u';
			break;
		case getDown():
			return 'd';
			break;
		case getLeft():
			return 'l';
			break;
        case getRight():
            return 'r';
            break;
        case getPause():
            return 'p';
            break;
        case getEnter():
            return 'e';
            break;
		case getQuit():
			return 'q';
			break;
		default:
			break;
	} */
	return ' ';
}

#include <string>
#include <ncurses.h>

void homeMenu(int position, WINDOW* stdscr)
{
	
}

//get a character input
//change display to match input
//let previous loop know what happened
char homeCaseSelect(char action, int&position)
{
	switch (action) {
        case 'u':
            position += 3;
            position = position%4;
            break;
        case 'd':
            position += 1;
            position = position%4;
            break;
        case 'e':
            if (position%4 == 3){
                return 'o';	//(o)pen settings
                position = 0;
            }
            else
                return 's';	//(s)tart game
            break;
		case 'q':
			return 'q';		//(q)uit 
			break;
        default:
            break;
    }
	return 'm';				//(m)enu
}

#include <string>
#include <cstring>
#include <ncurses.h>
#include "score.h"

void printHomeMenu(int displayMode, Score *scores, WINDOW* stdscr)
{
	clear();
    addstr("\n"
		"\t******************************************************* \n"
		"\t*                                                     * \n"
		"\t*    #####    ##   ##     ###     ##   ##   #######   * \n"
		"\t*   ##   ##   ###  ##    ## ##    ##  ##    ##        * \n"
		"\t*   ##        #### ##   ##   ##   ## ##     ##        * \n"
		"\t*    #####    ## # ##   #######   ####      #######   * \n"
		"\t*        ##   ## ####   ##   ##   ## ##     ##        * \n"
		"\t*   ##   ##   ##  ###   ##   ##   ##  ##    ##        * \n"
		"\t*    #####    ##   ##   ##   ##   ##   ##   #######   * \n"
		"\t*                                                     * \n"
		"\t*     Press \'f\' to start!                             * \n"
		"\t*                                                     * \n"
		"\t*                          **************************** \n"
		"\t*     ");

    //Normal indent
    if(displayMode == 0)
        addstr("> NORMAL           ");
    else
		addstr("NORMAL             ");

    addstr("  *        HIGHSCORES        * \n"
		"\t*                          *                          * \n"
		"\t*     ");

    //Hard indent
    if( displayMode == 1)
        addstr("> HARD             ");
    else
        addstr("HARD               ");

//first score
	std::string scoreString = scores[5*displayMode].getScoreString();
	char array[scoreString.size() +1];
	strcpy(array, scoreString.c_str());

	addstr(array);
    addstr("   * \n"
		"\t*                          *                          * \n"
		"\t*     ");

    //Extreme indent
    if( displayMode == 2)
        addstr("> EXTREME          ");
    else
        addstr("EXTREME            ");
//second score
    scoreString = scores[5*displayMode + 1].getScoreString();
    strcpy(array, scoreString.c_str());
    
	addstr(array);
    addstr("   * \n"
		"\t*                          *                          * \n"
		"\t*                        ");

//third score
    scoreString = scores[5*displayMode + 2].getScoreString();
    strcpy(array, scoreString.c_str());

    addstr(array);
    addstr("   * \n"
		"\t*                          *                          * \n"
		"\t*     ");

    //Settings indent
    if( displayMode == 3)
        addstr("> SETTINGS         ");
    else
        addstr("SETTINGS           ");

//fourth score
	scoreString = scores[5*displayMode + 3].getScoreString();
    strcpy(array, scoreString.c_str());

    addstr(array);
	addstr("   * \n"
		"\t*                          *                          * \n"
		"\t*                        ");

//Fifth score
    scoreString = scores[5*displayMode + 4].getScoreString();
    strcpy(array, scoreString.c_str());

    addstr(array);
	addstr("   * \n"
		"\t*                          *                          * \n"
		"\t******************************************************* \n"
		"\n");
	
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

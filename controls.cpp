#include <ncurses.h>

#include "controls.h"

Controls::Controls()
{
    //get controls from file
    //readFromFile
    up      = 'w';
    down    = 's';
    left    = 'a';
    right   = 'd';
    pause   = 'p';
    enter   = 'f';
    quit    = 'q';
}

/* Returns a key based on button pressed
 *  (u)p    (d)own  (l)eft  (r)ight
 *  (p)ause (e)nter (q)uit  
 *	( ) no match
 */
char Controls::handleKeypress(int receivedFromGetch)
{
    int ch = receivedFromGetch;
    if(ch == getUp())
        return 'u';
    else if(ch == getDown())
        return 'd';
    else if(ch == getLeft())
        return 'l';
    else if(ch == getRight())
        return 'r';
    else if(ch == getPause())
        return 'p';
    else if(ch == getEnter())
        return 'e';
    else if(ch == getQuit())
        return 'q';
    else
        return ' ';
}

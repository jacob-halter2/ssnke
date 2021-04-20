/* Dependencies
 *  score.h
 */
#include <string>
#include <cstring>
#include <fstream>

#include "score.h"


Score::Score()
{
	this->score = 0;    
	for (int k = 0; k < 3; k++) 
	{ 
		this->initials[k] = '.'; 
	}
}

Score::Score(int s, char i[]) //has data
{
	score = s;
    for (int k = 0; k < 3; k++)
    {
		if(i[k])
			initials[k] = i[k];
        else
            initials[k] = ' ';
    }
}

/*************************** GETTERS AND SETTERS ******************************/
/**/
int Score::getScore()
{
	return this->score;
}

/**/
char* Score::getInit()     
{ 
	return this->initials; 
}

/**/
void Score::setScore(int s)     
{ 
	this->score = s; 
}

/**/
void Score::setInit(char i [])  
{
	for (int k = 0; k < 3; k++)	
	{
        if(i[k])
            this->initials[k] = i[k];
        else
            this->initials[k] = ' ';
    }
}
    

/********************************** METHODS ***********************************/
/**/
int spaceSize(int i)
{
	if (i < 10)
        return 12;
    else return spaceSize(i/10) - 1;

}

std::string Score::getScoreString()
{
	std::string scoreString = "";
	int width = spaceSize( this->getScore() );
	scoreString += "  *  ";
	scoreString += this->getInit(); 
	scoreString += "  |  ";
	for( int i = 0; i < width; i++)
		{ scoreString += ' '; }
	scoreString += std::to_string(this->getScore());
	return scoreString;
}	





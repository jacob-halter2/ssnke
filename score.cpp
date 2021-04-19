/* Dependencies
 *  score.h
 */

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
void Score::printScore()
{

}





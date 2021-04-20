#pragma once

class Score
{
public:
	//structors
	Score(); //default no data
    Score(int s, char i[]);	//for given data
    ~Score() { ; }

    //getters/setters
    int getScore();
    char* getInit();
    void setScore(int s);
    void setInit(char i []);

    //methods
    std::string getScoreString();

private:
    int score;
    char initials[3]; 
};

#pragma once

class node
{
public:
    node() : p_prev(nullptr), p_next(nullptr) { }
    node(int y, int x) : p_prev(nullptr), p_next(nullptr), ypos(y), xpos(x) {}
    ~node() {}

    node * p_prev;
    node * p_next;
	
	void getPos(int &y, int &x) { y = this->ypos; x = this->xpos; }
    
	//private:
	int ypos;
	int xpos;
};

class list
{
public:
    //list
    list(int y, int x);
    //list(char d, int y, int x);

    void shiftOne();    //basic move for snake, head and tail move 1 space
    void becomeNewHead(node* p_temp);	//p_temp becomes the new head for the snake
	void addToHead();   //list grows by adding 1 node and moving only the head
    void removeTail();  //list shrinks by 1 by removing the tail

    int getSize() { return this->size; }
	char getDirection() { return this->direction; }
	
	//obtain coords
    void getHead(int &y, int &x);
	void getTail(int &y, int &x);
	
private:
    int size;   //includes the head oooox is size 5
    char direction;	
    node * head;
    node * tail;
};

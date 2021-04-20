#include "snakeBody.h"

//if no direction is supplied assumed snake is facing west
list::list(int y, int x)
{
    this->size = 1;
    this->direction = 'w';
	node *p_temp = new node(y,x);
    head = p_temp;
	tail = p_temp;
	//addToHead(4);	//should add 4 
}

void list::shiftOne()
{
    addToHead();
    removeTail();
}

void list::becomeNewHead(node* p_temp)
{	
	//connect head to temp;
	this->head->p_prev = p_temp;
	p_temp->p_next = head;

	//temp become the new head;
	this->head = p_temp;
}

void list::addToHead()
{
    char dir = this->getDirection();
	int headx, heady;
	this->getHead(heady,headx);
	node* p_temp;
	switch(dir)
	{
		case 'u':
			p_temp = new node(heady-1,headx);
		case 'd':
			p_temp = new node(heady+1,headx);
		case 'l':
            p_temp = new node(heady,headx-1);
        case 'r':
            p_temp = new node(heady,headx+1);
	}
	becomeNewHead(p_temp);		
}

void list::removeTail()
{
	this->tail->p_prev->p_next = nullptr;
	this->tail = this->tail->p_prev;
}

void list::getHead(int &y, int &x)
{
	this->head->getPos(y,x);
}

void list::getTail(int &y, int &x)
{
	this->tail->getPos(y,x);
}


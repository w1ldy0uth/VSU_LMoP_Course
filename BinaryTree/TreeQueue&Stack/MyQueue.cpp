#include "MyQueue.h"
#include "MyBinaryTree.h"
#include <iostream>

TQueue initQueue(TQueue& beg)
{
	beg = 0;
	return beg;
}

void clearQueue(TQueue& beg, TQueue& end)
{
	while (!isEmpty(beg))
		deQueue(beg);
}

void enQueue(TQueue& beg, TQueue& end, TTree elem)
{
	TQueue p = new QueueNode;
	p->data = elem;
	p->next = 0;
	if (isEmpty(beg))
		beg = p;
	else
		end->next = p;
	end = p;
}

void deQueue(TQueue& beg)
{
	if (!isEmpty(beg)) {
		TQueue p = beg;
		beg = beg->next;
		p->next = 0;
		delete p;
		p = 0;
	}
	else
		std::cout << "The queue is empty.";

}

void deQueue(TQueue& beg, TQueue& end, TTree& pNode)
{
	TQueue p = beg;
	pNode = p->data;
	beg = beg->next;
	p->next = 0;
	delete p;
	p = 0;
}

bool isEmpty(TQueue beg)
{
	return beg == 0;
}

void getFront(TQueue beg, TTree& elem)
{
	if (!isEmpty(beg))
		elem = beg->data;
	else
		std::cout << "The Queue is empty" << std::endl;
}

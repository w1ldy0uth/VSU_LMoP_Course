#include "MyStack.h"

void initStack(TStack& top)
{
	top = 0;
}

bool isEmpty(TStack top)
{
	return top == 0;
}

void push(TStack& top, TTree elem)
{
	TStack p = new StackNode;
	p->data = elem;
	p->next = top;
	top = p;
}

void pop(TStack& top)
{
	TStack p = top;
	top = top->next;
	p->next = 0;
	delete p;
}

void pop(TStack& top, TTree& elem)
{
	TStack p = top;
	top = top->next;
	elem = p->data;
	p->next = 0;
	delete p;
}

void clearStack(TStack& top)
{
	while (!isEmpty(top)) {
		pop(top);
	}
	top = 0;
}

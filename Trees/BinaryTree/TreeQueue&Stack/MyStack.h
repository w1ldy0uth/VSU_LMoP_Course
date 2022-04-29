#pragma once
#include "MyBinaryTree.h"

struct StackNode {
	TTree data;
	StackNode* next;
};

typedef StackNode* TStack;

void initStack(TStack& top);
bool isEmpty(TStack top);
void push(TStack& top, TTree elem);
void pop(TStack& top);
void pop(TStack& top, TTree& elem);
void clearStack(TStack& top);

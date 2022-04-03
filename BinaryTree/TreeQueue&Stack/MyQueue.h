#pragma once
#include "MyBinaryTree.h"

struct QueueNode {
	TTree data;
	QueueNode* next;
};

typedef QueueNode* TQueue;
//typedef TTree TypeData;

TQueue initQueue(TQueue& beg);
void clearQueue(TQueue& beg, TQueue& end);
void enQueue(TQueue& beg, TQueue& end, TTree elem);
void deQueue(TQueue& beg);
void deQueue(TQueue& beg, TQueue& end, TTree& elem);
bool isEmpty(TQueue beg);
void getFront(TQueue beg, TTree& elem);

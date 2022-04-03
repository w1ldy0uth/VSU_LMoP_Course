#pragma once
#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
};

typedef Node* TTree;
typedef void(*FunctionType) (int& node);

void initTree(TTree& root);
void initTree(TTree& root, int elem);

void destroyTree(TTree& root);

bool isEmpty(TTree root);
void print(TTree root, int h);

void insertElement(TTree root, int val);
void deleteElement(TTree rot, int val);

TTree search(TTree root, int key);
TTree searchIterative(TTree root, int key);

void copyTree(TTree root, TTree& newRoot);

void preorder(TTree root, FunctionType visit);
void inorder(TTree root, FunctionType visit);
void postorder(TTree root, FunctionType visit);

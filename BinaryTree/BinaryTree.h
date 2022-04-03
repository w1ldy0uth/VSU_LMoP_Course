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
void initTree(TTree& root, int elem, TTree leftTree, TTree rightTree);

void destroyTree(TTree& root);

bool isEmpty(TTree root);
void print(TTree root, int h);

int getRootData(TTree root);
void setRootData(TTree& root, int elem);

void attachLeftSon(TTree root, int elem);
void attachRightSon(TTree root, int elem);

void attachLeftSubtree(TTree root, TTree subTree);
void attachRightSubtree(TTree root, TTree subTree);

TTree getLeftSubtree(TTree root); //создает копию левого поддерева
TTree getLRightSubtree(TTree root);

void detachLeftSubtree(TTree root, TTree& leftTree);
void detachRightSubtree(TTree root, TTree& rightTree);

void copyTree(TTree root, TTree& newRoot);

void preorder(TTree root, FunctionType visit);
void inorder(TTree root, FunctionType visit);
void postorder(TTree root, FunctionType visit);

void inorderIterative(TTree root, FunctionType visit);

void breadthTraverse(TTree root, FunctionType visit);

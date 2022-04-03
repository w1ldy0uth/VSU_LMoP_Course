#include "BinaryTree.h"

void initTree(TTree& root) {
	root = nullptr;
}

void initTree(TTree& root, int elem) {
	root = new Node;
	root->data = elem;
	root->left = nullptr;
	root->right = nullptr;
	assert(root != nullptr);
}

void initTree(TTree& root, int elem, TTree leftTree, TTree rightTree) {
	initTree(root, elem);
	attachLeftSubtree(root, leftTree);
	attachRightSubtree(root, rightTree);
}

void destroyTree(TTree& root) {
	if (root != nullptr) {
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
		root = nullptr;
	}
}

bool isEmpty(TTree root) {
	return root == nullptr;
}

int getRootData(TTree root){
	if (!isEmpty(root))
		return root->data;
	else
		std::cout << "The tree is empty" << std::endl;
}

void setRootData(TTree& root, int elem) {
	if (!isEmpty(root)) {
		root->data = elem;
	}
	else
		initTree(root, elem);
}

void attachLeftSon(TTree root, int elem) {
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else {
		if (root->left != nullptr)
			std::cout << "Left subtree is not empty" << std::endl;
		else {
			TTree p = new Node;
			p->data = elem;
			p->left = nullptr;
			p->right = nullptr;
			root->left = p;
		}
	}
}

void attachRightSon(TTree root, int elem) {
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else {
		if (root->right != nullptr)
			std::cout << "Left subtree is not empty" << std::endl;
		else {
			TTree p = new Node;
			p->data = elem;
			p->left = nullptr;
			p->right = nullptr;
			root->right = p;
		}
	}
}


void print(TTree root, int h) {
	if (root != nullptr) {
		print(root->right, h + 1);
		for (int i = 0; i < h; i++)
			cout << " ";
		cout << root->data << "\n";
		print(root->left, h + 1);
	}
}

void attachLeftSubtree(TTree root, TTree subTree) {
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else {
		if (root->left != nullptr)
			std::cout << "Left subtree is not empty" << std::endl;
		else {
			root->left = subTree;
		}
	}
}

void attachRightSubtree(TTree root, TTree subTree) {
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else {
		if (root->right != nullptr)
			std::cout << "Left subtree is not empty" << std::endl;
		else {
			root->right = subTree;
		}
	}
}


TTree getLeftSubtree(TTree root) {
	TTree subTree;
	if (isEmpty(root)) {
		subTree = nullptr;
	}
	else {
		copyTree(root->left, subTree);
	}
	return subTree;
}

TTree getRightSubtree(TTree root) {
	TTree subTree;
	if (isEmpty(root)) {
		subTree = nullptr;
	}
	else {
		copyTree(root->right, subTree);
	}
	return subTree;
}

void detachLeftSubtree(TTree root, TTree& leftTree) {
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else {
		leftTree = root->left;
		root->left = nullptr;
	}
}

void detachRightSubtree(TTree root, TTree& rightTree) {
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else {
		rightTree = root->right;
		root->right = nullptr;
	}
}


void copyTree(TTree root, TTree& newRoot) {
	if (root != nullptr) {
		newRoot = new Node;
		newRoot->data = root->data;
		newRoot->left = nullptr;
		newRoot->right = nullptr;

		copyTree(root->left, newRoot->left);
		copyTree(root->right, newRoot->right);
	}
	else
		newRoot = nullptr;
}

void preorder(TTree root, FunctionType visit) {
	if (root != nullptr) {
		visit(root->data);
		preorder(root->left, visit);
		preorder(root->right, visit);
	}
}

void inorder(TTree root, FunctionType visit) {
	if (root != nullptr) {
		inorder(root->left, visit);
		visit(root->data);
		inorder(root->right, visit);
	}
}

void postorder(TTree root, FunctionType visit) {
	if (root != nullptr) {
		postorder(root->left, visit);
		postorder(root->right, visit);
		visit(root->data);
	}
}

void inorderIterative(TTree root, FunctionType visit) {
	TStack stack;
	initStack(stack);
	TTree cur = root;
	bool done = false;
	while (!done) {
		if (cur != nullptr) {
			push(stack, cur);
			cur = cur->left;
		}
		else {
			if (!isEmpty(stack)) {
				pop(stack);
				visit(cur->data);
				cur = cur->right;
			}
			else {
				done = true;
			}
		}
	}
}

void breadthTraverse(TTree root, FunctionType visit) {
	if (isEmpty(root)) {
		return;
	}
	TQueue head;
	TQueue tail = initQueue(head);
	TTree treeNode = root;
	enQueue(head, tail, treeNode);
	while (!isEmpty(head)) {
		deQueue(head, tail, treeNode);
		visit(treeNode->data);
		if (treeNode->left)
			enQueue(head, tail, treeNode->left);
		if (treeNode->right)
			enQueue(head, tail, treeNode->right);
	}
}

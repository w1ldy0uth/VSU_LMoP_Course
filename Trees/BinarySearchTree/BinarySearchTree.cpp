#include "BinarySearchTree.h"

void initTree(TTree& root) {
	root = nullptr;
}

void initTree(TTree& root, int elem) {
	root = new Node;
	root->data = elem;
	root->left = nullptr;
	root->right = nullptr;
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

void print(TTree root, int h) {
	if (root != nullptr) {
		print(root->right, h + 1);
		for (int i = 0; i < h; i++)
			cout << " ";
		cout << root->data << "\n";
		print(root->left, h + 1);
	}
}

void insertElement(TTree root, int val) {
    if (root == nullptr)
        initTree(root, val);
    else {
        if (val < root->data)
            insertElement(root->left, val);
        else
            insertElement(root->right, val);
    }
}

void deleteElement(TTree &root, int val) {
    if (root == nullptr)
        cout << "Not found\n";
    else {
        if (val == root->data)
            deleteNode(root);
        else {
            if (val < root->data)
                deleteElement(root->left, val);
            else
                deleteElement(root->right, val);
        }
    }
}

void deleteNode(TTree &pNode) {
    if (pNode->left == nullptr && pNode->right == nullptr) {
        delete pNode;
        pNode = nullptr;
    }
    else {
        TTree delNode;
        if (pNode->left == nullptr || pNode->right == nullptr) {
            delNode = pNode;
            if (pNode->left == nullptr)
                pNode = pNode->right;
            else
                pNode = pNode->left;
            delete delNode;
            delNode = nullptr;
        }
        else
            pNode->data = findSuccessor(pNode->right);
    }
}

int findSuccessor(TTree &pNode) {
    if (pNode->left == nullptr) {
        int val = pNode->data;
        TTree delNode = pNode;
        pNode = pNode->right;
        delete delNode;
        return val;
    }
    findSuccessor(pNode->left);
}

TTree search(TTree root, int key) {
    if (root == nullptr)
        return nullptr;
    else {
        if (key == root->data)
            return root;
        else {
            if (key < root->data)
                search(root->left, key);
            else
                search(root->right, key);
        }
    }
}


TTree searchIterative(TTree root, int key) {
    while (root != nullptr && root->data != key) {
        if (root->data < key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
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

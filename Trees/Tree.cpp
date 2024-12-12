#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int);

int main()
{
	Node* root = createNode(1);

	root->left = createNode(2);
	root->right = createNode(3);

	root->left->left = createNode(4);
	root->left->right = createNode(5);

	root->right->left = createNode(6);
	root->right->right = createNode(7);

	root->left->right->left = createNode(9);
	root->right->right->left = createNode(15);

	return 0;
}

Node* createNode(int val)
{
	Node* newNode = new Node();
	newNode->data = val;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}


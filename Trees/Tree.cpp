#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int);
void printTreePRE(Node*);
void printTreeIN(Node*);
void printTreePOST(Node*);


int main()
{
	
	// Create Tree
	Node* root = createNode(1);

	root->left = createNode(2);
	root->right = createNode(3);

	root->left->left = createNode(4);
	root->left->right = createNode(5);

	root->right->left = createNode(6);
	root->right->right = createNode(7);

	root->left->right->left = createNode(9);
	root->right->right->left = createNode(15);
	// End of creating Tree

	cout << "PreOrder:\t";
	printTreePRE(root);
	cout << "\n";

	cout << "Inorder:\t";
	printTreeIN(root);
	cout << "\n";

	cout << "PostOrder:\t";
	printTreePOST(root);
	cout << "\n";

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


// Uses the Preorder algorithm to print Tree (DFS method 1)
void printTreePRE(Node* root) {
	// Base case
	if (root == nullptr) return;

	// Print Data
	cout << root->data << "\t";
	// Check left
	printTreePRE(root->left);
	// Check right
	printTreePRE(root->right);
}



// Uses Inorder Traversal Algorithm, (DFS Method 2)
void printTreeIN(Node* root){
	// Base case
	if (root == nullptr) return;

	// Check left
	printTreeIN(root->left);
	// Print Data
	cout << root->data << "\t";
	// Check right
	printTreeIN(root->right);
}


// Uses Postorder Traversal Algorithm, DFS Method 3
void printTreePOST(Node* root) {
	// Base case
	if (root == nullptr) return;

	// Check left
	printTreePOST(root->left);
	// Check right
	printTreePOST(root->right);
	// Print data
	cout << root->data << "\t";
}

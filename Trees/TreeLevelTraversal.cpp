#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// We want to run BFS and a Queue
//
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* createNode(int data);

vector<vector<int>> levelOrder(TreeNode* root);

int main()
{
	// Create Tree
	TreeNode* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);

	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	
	root->right->right->left = createNode(15);
	root->right->right->right = createNode(17);


	vector<vector<int>> result = levelOrder(root);
	// end of creating Tree structure
	for (auto element: result)
	{
		for (auto sub_element : element)
		{
			cout << sub_element << " ";
		}

		cout << endl;
	}

	return 0;
}

TreeNode* createNode(int data)
{
	TreeNode* newNode = new TreeNode();
	newNode->val = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	if (!root) return result;

	deque<TreeNode*> queue;
	queue.push_back(root);

	while(!(queue.empty()))
	{
		int queue_length = queue.size();
		vector<int> level;

		for (int i = 0; i < queue_length; i++)
		{
			TreeNode* Node = queue.front();
			queue.pop_front();
			
			if (Node)
			{
				level.push_back(Node->val);
				if (Node->left) queue.push_back(Node->left);
				if (Node->right) queue.push_back(Node->right);
			}
		}

		if (!level.empty())
		{
			result.push_back(level);
		}
	}

	return result;
}


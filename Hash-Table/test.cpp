#include <iostream>
#include <map>
using namespace std;

// Data Structure to store a binary tree node
struct Node {
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}
};

// Recursive function to do a pre-order traversal of the tree and fill map
// Here node has 'dist' horizontal distance from the root of the tree
void printVertical(Node *node, int dist, auto &map)
{
	// base case: empty tree
	if (node == NULL)
		return;

	// insert nodes present at current horizontal distance into the map
	map.insert(make_pair(dist, node->data));

	// recur for left subtree by decreasing horizontal distance by 1
	printVertical(node->left, dist - 1, map);

	// recur for right subtree by increasing horizontal distance by 1
	printVertical(node->right, dist + 1, map);
}

// Function to perform vertical traversal of a given binary tree
void printVertical(Node *root)
{
	// create an empty map where
	// key -> relative horizontal distance of the node from root node and
	// value -> nodes present at same horizontal distance
	multimap<int, int> map;

	// we can also use map<int, vector<int>> instead of multimap<int, int>

	// do pre-order traversal of the tree and fill the map
	printVertical(root, 0, map);

	// traverse the map and print vertical nodes
	int temp = 0;
	for (auto it = map.begin(); it != map.end(); it++)
	{
		if (temp != it->first)
		{
			cout << endl;
			temp = it->first;
		}
		cout << it->second << " ";
	}
}

int main()
{
	/* Construct below tree
              1
            /   \
           /     \
          2       3
                /   \
               /     \
              5       6
            /   \
           /     \
          7       8
                /   \
               /     \
              9      10
	*/

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);
	root->right->left->right->left = new Node(9);
	root->right->left->right->right = new Node(10);

	printVertical(root);

	return 0;
}

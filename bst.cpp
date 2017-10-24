#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

// void inOrder(Node* root)
// {
// 	if(root==nullptr)
// 		return;

// 	inOrder(root->left);
// 	cout << root->data;
// 	inOrder(root->right);

// 	return;
// }

Node* insert(Node* &root, int key)
{
	if(root==nullptr)
		return newNode(key);

	if(key < root->data)
	{
		root-> left = insert(root->left, key);
	}
	else
 		root->right = insert(root->right, key);

 	return root;
}

void search(Node* root, int key)
{
	if(root == nullptr)
		cout << "Not found" << endl; return;

	if(root->data == key)
		cout << "Key found"; return;

	if(key < root->data)
	{
		search(root->left, key);
	}
	else 
		search(root->right, key);
}

Node* minKey(Node* curr)
{
	while(curr->left!=nullptr)
	{
		curr = curr->left;
	}

	return curr;

}
// Function to find a given key in the BST
void searchKey(Node* &root, int key, Node* &parent)
{
	while(root!=nullptr && key != root->data)
	{
		parent = root;

		if(key < root->data)
		{
			searchKey(root->left, key, parent);
		}
		else 
			searchKey(root->right, key, parent);
	}
}

// Function to delete a node in a BST
void deleteNode(Node* &root, int key)
{
	Node* parent = nullptr; 

	Node* curr = root;

	searchKey(root, key, parent);

	if(curr == nullptr)
		return;

	// Case 1: node to be deleted is a leaf node
	if(curr -> left == nullptr && curr->right == nullptr)
	{
		if(curr!=root)
		{
			if(parent->left == curr)
			{
				parent->left = nullptr;
			}
			else 
				parent->right = nullptr;
		}
		else
			root = nullptr;

		delete(curr);
	}

	// Case 2: Node to be deleted has two children
	else if(curr -> left && curr->right)	
	{
		Node* successor = minKey(curr);

		int val = successor->data;

		deleteNode(root, successor->data);

		curr->data = val;
	}

	// Case 3: node to be deleted has only one child
	else
	{
		Node* child = (curr->left) ? curr->left : curr->right;

		if(curr!=root)
		{
			if(curr == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}
		else
			root = child;

		delete(curr);
	}

}

// // Construct BST from a sorted array 
// void convert(int[] keys, int low, int high, Node* &root)
// {
// 	if(low > high)
// 		return;

// 	int mid = low + (high - low)/2;

// 	root = newNode(keys[mid]);

// 	convert(keys, low, mid - 1, root->left);

// 	convert(keys, mid + 1, high, root->right);
// }

// Node* convert(int keys[], int n)
// {
// 	sort(keys, keys+n);

// 	Node* root = nullptr;
// 	convert(keys, 0, n - 1, root);

// 	return root;
// }

// Determine if given tree is BST or Not

bool isBST(Node* root, int minKey, int maxKey)
{
	if(root == nullptr)
		return true;

	if(root->data < minKey || root->data > maxKey)
	{
		return false;
	}

	return isBST(root->left, minKey, root->data) &&
			isBST(root->right, root->data, maxKey);
}

int isBST(Node* root)
{
	if(isBST(root,INT_MIN, INT_MAX))
		return 1;
	else
		return 0;
}

// // Check if two arrays represent the same BST
// int sameBST(int* X, int* Y, int n)
// {
// 	if(n==0 || n==1)
// 		return 1;

// 	int leftX[n-1], rightY[n-1], rightX[n-1], leftY[n-1];

// 	int k = 0, l =0, m = 0, o = 0;

// 	if(X[0]!=Y[0]) return false;

// 	for(int i = 1; i < n; i++)
// 	{
// 		if(X[i] < X[0])
// 			leftX[k++] = X[i];
// 		else 
// 			rightX[l++] = X[i];

// 		if(Y[i] < Y[0])
// 			leftY[m++] = Y[i];
// 		else 
// 			rightY[o++] = Y[i];
// 	}

// 	if(leftX.size() != leftY.size() || rightX.size() != rightY.size())
// 		return false;

// 	return sameBST(leftX, leftY, k) && sameBST(rightX, rightY, l);
// }

vector<int> inOrder(Node* root)
{
	static vector<int> result;

	if(!root)
		return result;

	inOrder(root->left);
	result.push_back(root->data);
	inOrder(root->right);

	return result;
}

// InOrder predecessor of the node
int inOrderPred(Node* root, int key)
{
	vector<int> inOrderVector;
	inOrderVector =  inOrder(root);

	if(find(inOrderVector.begin(), inOrderVector.end(), key) != inOrderVector.end())
	{
		vector<int>::iterator it = find(inOrderVector.begin(), inOrderVector.end(), key);
		if(it!=inOrderVector.begin())
			return *(it-1);
	}
	
	return -1;
}

int main()
{
	Node* root = nullptr;

	int keys[] = {1, 2, 3, 12, 5, 8, 10};
	int n = sizeof(keys)/sizeof(int);
	for(int i = 0; i < n; i++)
	{
		root = insert(root, keys[i]);
	}

	cout << "In order predecessor is: " << inOrderPred(root, 8);

	return(0);
}























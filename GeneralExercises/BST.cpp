#include "CP.h"


struct Node {
	int Data;
	Node* Left;
	Node* Right;
};

class BinarySearchTree {

public:
	Node* Bst;
	void driverFun();
	Node* init(int node);
	Node* addNode(Node* root, int node);
	void inOrder(Node* node);
	void preOrder(Node* node);
	void postOrder(Node* node);
	Node* findWithValue(int val);
	Node* deleteNode(Node* root, int val);
	Node* inorderPredecessor(Node* givenNode, Node*& res, int key);
	Node* inorderSuccessor(Node* givenNode, Node*& res, int key);
	Node* minNode(Node* root);
	Node* maxNode(Node* root);
	int countBST(Node* root);
	bool isBST(Node* root);
	Node* convertTreeToBST(Node* root);
private:
	void BinaryTreeToArray(Node* root, int inorder[], int& idx);
	void ArrayToBinarySearchTree(Node* root, int inorder[], int& idx);
};

inline void BinarySearchTree::driverFun()
{
	Node* root = NULL;
	Node* succ = NULL, * pre = NULL;
	root = addNode(root, 50);
	//root->Left = addNode(root->Left, 100);   // to invalidate BST role isBST(root)=>False
	addNode(root, 30);
	addNode(root, 20);
	addNode(root, 40);
	addNode(root, 70);
	addNode(root, 60);
	addNode(root, 80);


	//Data To convert BT to BST
	/*root = addNode(root, 10);
	root->Left = addNode(root->Left, 30);
	root->Right = addNode(root->Right, 15);
	root->Left->Left = addNode(root->Left->Left, 20);
	root->Right->Right = addNode(root->Right->Right, 5);*/


	cout << (isBST(root) ? "True" : "False") << endl;
	cout << "InOrder: "; inOrder(root); cout << endl;
	cout << "PreOrder: "; preOrder(root); cout << endl;
	cout << "PostOrder: "; postOrder(root); cout << endl;
	cout << "Min: " << minNode(root)->Data << endl;
	cout << "Max: " << maxNode(root)->Data << endl;
	cout << "Successor after 65: " << inorderSuccessor(root, succ, 65)->Data << endl;
	cout << "Predecessor before 65: " << inorderPredecessor(root, pre, 65)->Data << endl;

	//REP(i, 20)cout << "=";
	//cout << endl;
	//convertTreeToBST(root);
}

inline Node* BinarySearchTree::init(int node) {
	Bst = new Node;
	Bst->Data = node;
	Bst->Left = NULL;
	Bst->Right = NULL;
	return Bst;
}

inline Node* BinarySearchTree::addNode(Node* root, int node)
{
	if (root == NULL) {
		root = init(node);
	}
	else if (node <= root->Data)
	{
		root->Left = addNode(root->Left, node);
	}
	else
	{
		root->Right = addNode(root->Right, node);
	}
	return root;
}

inline void BinarySearchTree::inOrder(Node* node)
{
	if (node == NULL) return;
	inOrder(node->Left);
	cout << node->Data << " ";
	inOrder(node->Right);
}

inline void BinarySearchTree::preOrder(Node* node)
{
	if (node == NULL)return;
	cout << node->Data << " ";
	preOrder(node->Left);
	preOrder(node->Right);
}

inline void BinarySearchTree::postOrder(Node* node)
{
	if (node == NULL)return;
	postOrder(node->Left);
	postOrder(node->Right);
	cout << node->Data << " ";
}

inline Node* BinarySearchTree::findWithValue(int val) {
	Node* curr = Bst;
	Node* res = NULL;
	while (curr)
	{
		if (val == curr->Data) { res = curr; break; }
		else if (val < curr->Data) curr = curr->Left;
		else if (val > curr->Data) curr = curr->Right;
	}
	return res;
}

inline Node* BinarySearchTree::deleteNode(Node* root, int val)
{
	if (root == NULL)return root;
	if (root->Data < val) {
		deleteNode(root->Right, val);
	}
	else if (root->Data > val) {
		deleteNode(root->Left, val);
	}
	else
	{
		if (root->Left == NULL && root->Right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->Left == NULL) {
			Node* tmp = root;
			root->Right = root->Right;
			delete tmp;
		}
		else if (root->Right == NULL) {
			Node* tmp = root;
			root->Left = root->Left;
			delete tmp;
		}
		else {
			Node* min = minNode(root->Right);
			root->Data = min->Data;
			root->Right = deleteNode(root->Right, root->Data);
		}
	}
	return root;
}

inline Node* BinarySearchTree::inorderPredecessor(Node* node, Node*& res, int key)
{
	// (first node less than the givenNode) right most node in the left part of given node
	if (node == NULL) return NULL;
	if (node->Data == key) {
		if (node->Left != NULL) {
			Node* tmp = node->Left;
			while (tmp->Right)
				tmp = tmp->Right;
			res = tmp;
		}
	}
	else if (node->Data < key) {
		res = node;
		inorderPredecessor(node->Right, res, key);
	}
	else {
		inorderPredecessor(node->Left, res, key);
	}
	return res;
}

inline Node* BinarySearchTree::inorderSuccessor(Node* node, Node*& res, int key)
{
	// (first node greater than the givenNode) left most node in the right part of given node
	if (node == NULL)return NULL;
	if (node->Data == key) {
		if (node->Right != NULL) {
			Node* tmp = node->Right;
			while (tmp->Left) {
				tmp = tmp->Left;
			}
			res = tmp;
		}
	}
	if (node->Data > key) {
		res = node;
		inorderSuccessor(node->Left, res, key);
	}
	else {
		inorderSuccessor(node->Right, res, key);
	}
	return res;
}

inline Node* BinarySearchTree::minNode(Node* root)
{
	//Node* res = root;
	if (root == NULL)return root;
	while (root->Left != NULL)
		root = root->Left;
	return root;
	//	return(root->Left != NULL) ? root = minNode(root->Left) : root;
}

inline Node* BinarySearchTree::maxNode(Node* root)
{
	//Node* res = NULL;
	if (root == NULL)return root;
	while (root->Right != NULL)
		root = root->Right;
	return root;
	//return(root->Right != NULL) ? root = minNode(root->Right) : root;
}

inline int BinarySearchTree::countBST(Node* root)
{
	if (root == NULL) return 0;

	return countBST(root->Right) + countBST(root->Left) + 1;
}

inline bool BinarySearchTree::isBST(Node* root)
{
	Node* tmp = root;
	if (root->Right != NULL) {
		if (root->Right->Data < tmp->Data) return false;
		isBST(root->Right);
	}
	if (root->Left != NULL) {
		if (root->Left->Data > tmp->Data) return false;
		isBST(root->Left);
	}
	return true;
}

inline Node* BinarySearchTree::convertTreeToBST(Node* root)
{
	int n = countBST(root);
	int* arr = new int[n];
	int idx = 0;
	BinaryTreeToArray(root, arr, idx);
	sort(arr, arr + n);
	idx = 0;
	ArrayToBinarySearchTree(root, arr, idx);
	delete[]arr;
	return root;
}

inline void BinarySearchTree::BinaryTreeToArray(Node* root, int inorder[], int& idx)
{
	if (root == NULL) return;
	BinaryTreeToArray(root->Left, inorder, idx);
	inorder[idx] = root->Data;
	idx++;
	BinaryTreeToArray(root->Right, inorder, idx);
}

inline void BinarySearchTree::ArrayToBinarySearchTree(Node* root, int inorder[], int& idx)
{
	if (root == NULL) return;
	ArrayToBinarySearchTree(root->Left, inorder, idx);
	root->Data = inorder[idx];
	idx++;
	ArrayToBinarySearchTree(root->Right, inorder, idx);
}












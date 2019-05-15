#include "pch.h"
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node *GetNewNode(int data) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *Insert(Node *root, int data) {
	if (root == NULL)
		root = GetNewNode(data);
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

bool Search(Node *root, int data) {
	if (root == NULL) return false;
	else if (data == root->data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

//Iterative solution to find the max value of the tree 
int FindMax(Node *root) {
	if (root == NULL) {
		cout << "Tree is empty\n";
		return -1;
	}
	while (root->right != NULL) root = root->right;
	return root->data;
}

//using recursion to find the min value of the tree
int FindMaxx(Node *root) {
	if (root == NULL) {
		cout << "Tree is empty\n";
		return -1;
	}
	else if (root->right == NULL) return root->data;
	return FindMaxx(root->right);
}

//Iterative solution to find the min value of the tree 
int FindMin(Node *root) {
	if (root == NULL) {
		cout << "Tree is empty\n";
		return -1;
	}
	while (root->left != NULL) root = root->left;
	return root->data;
}

//using recursion to find the min value of the tree
int FindMinn(Node *root) {
	if (root == NULL) {
		cout << "Tree is empty\n";
		return -1;
	}
	else if (root->left == NULL) return root->data;
	return FindMinn(root->left);
}

int FindHeight(Node *root) {
	if (root == NULL) return -1;
	else {
		int leftHeight = FindHeight(root->left);
		int rightHeight = FindHeight(root->right);

		if (leftHeight > rightHeight) return (leftHeight + 1);
		else return (rightHeight + 1);
	}
}

void PreOrder(Node *root) {
	cout << root->data << " ";
	if (root->left) PreOrder(root->left);
	if (root->right) PreOrder(root->right);
}

void InOrder(Node *root) {
	if (root->left) InOrder(root->left);
	cout << root->data << " ";
	if (root->right) InOrder(root->right);
}

void PostOrder(Node *root) {
	if (root->left) PostOrder(root->left);
	if (root->right) PostOrder(root->right);
	cout << root->data << " ";
}

Node *Delete(Node *root, int data) {
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->left == NULL) {
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		else {
			int temp = FindMin(root->right);
			root->data = temp;
			root->right = Delete(root->right, temp);
		}
	}
	return root;
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 12);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 14);
	root = Insert(root, 30);
	root = Insert(root, 23);
	root = Insert(root, 13);
	root = Insert(root, 10);
	root = Insert(root, 11);
	root = Delete(root, 12);

	cout << "PreOrder: ";
	PreOrder(root);
	cout << endl;

	cout << "InOrder: ";
	InOrder(root);
	cout << endl;

	cout << "PostOrder: ";
	PostOrder(root);
	cout << endl;

	cout << FindHeight(root) << endl;

	cout << FindMax(root) << endl;
	cout << FindMaxx(root) << endl;
	cout << FindMin(root) << endl;
	cout << FindMinn(root) << endl;

	int numb;

	cout << "Enter Number\n";
	cin >> numb;

	if (Search(root, numb) == true) cout << "Found\n";
	else cout << "Not Found\n";

	return 0;
}
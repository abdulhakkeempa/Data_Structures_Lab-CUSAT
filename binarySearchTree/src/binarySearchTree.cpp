//============================================================================
// Name        : binarySearchTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class BinaryTree;
class Node{
	int data;
	Node* left;
	Node* right;
public:
	Node(){
		data = 0;
		left = NULL;
		right = NULL;
	}
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
	friend class BinaryTree;
};

class BinaryTree{
	Node* root;
public:
	BinaryTree(){
		root = NULL;
	}
	void createNode(int val);
	void printNode();

};

void BinaryTree::printNode(){
	Node* temp = root;
	while(temp != NULL){
		cout<<temp->data<<endl;
		temp = temp->right;
	}
	cout<<temp->data<<endl;
}

void BinaryTree::createNode(int val){
	Node* newNode = new Node(val);
	if (root==NULL){
		root = newNode;
		return;
	}
	else if (val>root->data){
		if (root->right == NULL){
		root->right = newNode;
		return;
		}
		Node* temp = root->right;
		Node * currentNode;
		while (temp != NULL){
			cout<<temp->data<<endl;
			if (val>temp->data){
				temp = temp->right;
				currentNode = temp;
			}
			else if (val<temp->data){
				temp = temp->left;
				currentNode = temp;
			}
		}

		temp = newNode;
		currentNode->right = temp;
		cout<<temp->left<<" : "<<temp->data<<" : "<<temp->right<<endl;
	}
	root->left = newNode;
}

int main() {
	BinaryTree Tree;
//	Tree.createNode(5);
//	Tree.createNode(10);
//	Tree.createNode(4);
//	Tree.createNode(11);
//	Tree.printNode();
	Tree.checkNULL();
	return 0;
}

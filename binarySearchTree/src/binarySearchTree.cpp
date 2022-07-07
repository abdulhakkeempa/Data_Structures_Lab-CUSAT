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
public:
	Node* root;
	BinaryTree(){
		root = NULL;
	}
	void createNode(int val);
	void printNode(Node* node);

};

void BinaryTree::printNode(Node* node){

	 if (node == NULL)
	        return;

	    // first recur on left subtree
	    printNode(node->left);

	    // now deal with the node
	    cout << node->data << " ";

	    // then recur on right subtree
	    printNode(node->right);
}

void BinaryTree::createNode(int val){
	Node* newNode = new Node(val);
	if (root==NULL){
		root = newNode;
		return;
	}
	Node* temp = root;
	while (true){
		if(val<temp->data){
			if(temp->left==NULL){
				temp->left = newNode;
				break;
			}
			else{
				temp = temp->left;
			}
		}
		else {
			if(temp->right==NULL){
				temp->right = newNode;
				break;
			}
			else{
				temp = temp->right;
			}
		}
	}

}

int main() {
	BinaryTree Tree;
	Tree.createNode(5);
	Tree.createNode(10);
	Tree.createNode(4);
	Tree.createNode(11);
	Tree.createNode(15);
	Tree.createNode(20);
	Tree.printNode(Tree.root);
	return 0;
}

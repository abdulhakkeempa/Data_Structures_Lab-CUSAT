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
	void printNode();
	void inOrder(Node* node);
	void preOrder(Node* node);
	void postOrder(Node* node);
	void deleteNode(Node* node,int key);
	void smallFunction(int key){
		deleteNode(root, key);
	}
};

void BinaryTree::postOrder(Node* node){
	 if (node == NULL){
	        return;
	 }
	 postOrder(node->left);
	 postOrder(node->right);
	 cout<<node->data<<",";
}

void BinaryTree::preOrder(Node* node){
	 if (node == NULL){
	        return;
	 }
	 cout<<node->data<<",";
	 preOrder(node->left);
	 preOrder(node->right);
}

void BinaryTree::inOrder(Node* node){
	 if (node == NULL){
	        return;
	 }
	 inOrder(node->left);
	 cout<<node->data<<",";
	 inOrder(node->right);
}

void BinaryTree::printNode(){
	cout<<"In-Order"<<endl;
	inOrder(root);
	cout<<"\nPre-Order"<<endl;
	preOrder(root);
	cout<<"\nPost-Order"<<endl;
	postOrder(root);
	cout<<endl;
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

void BinaryTree::deleteNode(Node* node,int key){
	if (node==NULL){
		return;
	}
	else if(key==node->data){
		cout<<"found"<<endl;
	}
	else if(key>node->data){
		deleteNode(node->right, key);
	}
	else if(key<node->data){
		deleteNode(node->left, key);
	}
}

int main() {
	BinaryTree Tree;
	Tree.createNode(100);
	Tree.createNode(20);
	Tree.createNode(200);
	Tree.createNode(10);
	Tree.createNode(30);
	Tree.createNode(150);
	Tree.createNode(300);
	Tree.printNode();
	Tree.smallFunction(56);
	return 0;
}

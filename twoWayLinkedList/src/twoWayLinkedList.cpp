#include <iostream>
using namespace std;

class Node{
	int data;
	Node* left;
	Node* right;
public:
	Node(){
		this->left = NULL;
		this->right = NULL;
		this->data = 0;
	}
	Node(int val){
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
	int getValue(){
		return data;
	}
	void setValue(int val){
		this->data = val;
		this->right = NULL;
		this->left = NULL;
	}
	friend class LinkedList;
};

class LinkedList{
	Node* head;
	Node* last;
public:
	LinkedList(){
		head = NULL;
		last = NULL;
	}
	void createNode(int);
	void printFromFirst();
	void printFromBack();
};

void LinkedList::createNode(int val){
	Node* newNode = new Node(val);
	if(head==NULL){
		head = newNode;
		return;
	}
	Node* temp = head;
	Node* prev = NULL;
	while(temp->right!=NULL){
		prev = temp;
		temp = temp->right;
	}
	temp->left = prev;
	temp->right = newNode;
	last = temp->right;
}

void LinkedList::printFromFirst(){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->left<<" : "<<temp->data<<" : "<<temp->right<<endl;
		temp = temp->right;
	}
	cout<<endl;
}

void LinkedList::printFromBack(){
	Node* temp = last;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp = temp->left;
	}
}
int main() {
	LinkedList two;
	two.createNode(10);
	two.createNode(20);
	two.createNode(30);
	two.createNode(40);
	two.createNode(50);
	two.createNode(60);
	two.createNode(70);
	two.printFromFirst();
	two.printFromBack();

	return 0;
}

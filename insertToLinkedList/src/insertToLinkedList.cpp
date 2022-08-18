//============================================================================
// Name        : insertToLinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node{
	int data;
	Node* link;
public:
	Node(){
		this->data = 0;
		this->link = NULL;
	}
	Node(int val){
		this->data = val;
		this->link = NULL;
	}
	friend class LinkedList;
};

class LinkedList{
	Node* head;
public:
	LinkedList(){
		head = NULL;
	}
	void createNode(int val);
	void printNode();
	void insertInBetween(int val);
};

void LinkedList::createNode(int val){
	Node* newNode = new Node(val);
	if(head==NULL){
		head = newNode;
		return;
	}
	Node* temp = head;
	while(temp->link!=NULL){
		temp = temp->link;
	}
	temp->link = newNode;
}

void LinkedList::printNode(){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp = temp->link;
	}
}

void LinkedList::insertInBetween(int val){
	Node* temp = head;
	while(temp!=NULL){
		Node* succ = new Node();
		succ = temp->link;
		if(val>temp->data and val<succ->data){
			cout<<"Yes between "<<temp->data<<"& "<<succ->data<<endl;
		}
		temp = temp->link;
}
int main() {
	LinkedList list;
	list.createNode(10);
	list.createNode(20);
	list.createNode(25);
	list.createNode(30);
	list.createNode(40);
	list.printNode();
	list.insertInBetween(20);
	return 0;
}

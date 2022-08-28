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
	int getData(){
		return data;
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
	if(val<head->getData()){
//		cout<<"before head"<<endl;
		Node* newNode = new Node(val);
		newNode->link = head;
		head = newNode;
		return;
	}
	while(temp->link!=NULL){
		Node* succ = temp->link;
		if(val>temp->getData() and val<succ->getData()){
//			cout<<"Yes between "<<temp->data<<" & "<<succ->data<<endl;
			Node* newNode = new Node(val);
			newNode->link = succ;
			temp->link = newNode;
			return;
		}
		temp = temp->link;
	}
	if(val>temp->getData()){
		Node* newNode = new Node(val);
		temp->link = newNode;
	}
}

int main() {
	LinkedList list;
	list.createNode(10);
	list.createNode(20);
	list.createNode(25);
	list.createNode(30);
	list.createNode(40);
	list.printNode();
	list.insertInBetween(5);
	list.insertInBetween(45);
	list.insertInBetween(32);
	list.insertInBetween(-1);
	list.printNode();
//	list.printNode();
	return 0;
}

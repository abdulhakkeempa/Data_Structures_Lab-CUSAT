//============================================================================
// Name        : linkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class LinkedList;
class Node{
	int data;
	Node* link;
public:
	Node(){
		data = 0;
		link = NULL;
	}
    Node(int data){
        this->data = data;
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

	void addNode(int data);
	void printNodes();
	Node* searchItems(int item);
};

Node* LinkedList::searchItems(int item){
	Node* temp = head;
	while (temp !=NULL){
		if(temp->data==item){
			return temp;
		}
		temp = temp->link;
	}
	cout<<"Element not in the list"<<endl;
	return 0;
}

void LinkedList::printNodes(){
	if(head==NULL){
		cout<<"List Overflow"<<endl;
		return;
	}
	cout<<"Head : "<<head<<"-> "<<endl;
	Node* temp = head;
	while(temp !=NULL){
		cout<<temp->data<<" -> "<<temp->link<<endl;
		temp = temp->link;
	}
}

void LinkedList::addNode(int data){
	Node* NewNode = new Node(data);

	if(head == NULL){
		head = NewNode;
		return;
	}
	Node* temp = head;
//	cout<<temp->link<<endl;
	while (temp->link != NULL){
		temp = temp->link;
	}
	temp->link = NewNode;
}

int main() {
	LinkedList List;
	List.addNode(5);
	List.addNode(59);
	List.addNode(26);
	List.addNode(10);
	List.addNode(20);
	List.printNodes();

	Node* address = List.searchItems(100);
	cout<<address<<endl;
	return 0;
}

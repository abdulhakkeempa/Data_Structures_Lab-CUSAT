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
	void deleteNode(int key);
};

void LinkedList::printNodes(){
	if(head==NULL){
		cout<<"List Overflow"<<endl;
		return;
	}
	Node* temp = head;
	while(temp ->link!=head){
		if(temp->data<10){
			cout<<" ";
		}
		cout<<temp->data<<" | "<<temp->link<<" | "<<endl;
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
	while (temp->link != head){
		temp = temp->link;
	}
	temp->link = NewNode;
	NewNode->link = head;
}

int main() {
	LinkedList li1;
	li1.addNode(10);
	li1.addNode(20);
	li1.addNode(30);
	li1.addNode(40);
	li1.printNodes();
	return 0;
}

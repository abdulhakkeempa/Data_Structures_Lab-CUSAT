#include <iostream>
using namespace std;

class Node{
	int data;
	Node* link;
public:
	Node(){
		this->link = NULL;
		this->data = 0;
	}
	Node(int val){
		this->data = val;
		this->link = NULL;
	}
	int getValue(){
		return data;
	}
	void setValue(int val){
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
	void createNode(int);
	void printNode();
	void mergeList(LinkedList list1,LinkedList list2);
};

void LinkedList::createNode(int val){
	Node* newNode = new Node(val);
	if(head==NULL){
		head = newNode;
		return;
	}
	Node* temp = new Node();
	temp = head;
	while(temp->link!=NULL){
		temp = temp->link;
	}
	temp->link = newNode;
}

void LinkedList::printNode(){
	Node* temp = new Node();
	temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"  ";
		temp = temp->link;
	}
	cout<<endl;
}

void LinkedList::mergeList(LinkedList list1,LinkedList list2){
	Node* temp1 = list1.head;
	Node* temp2 = list2.head;
	while(temp1!=NULL and temp2!=NULL){
		if(temp1->getValue()>temp2->getValue()){
			createNode(temp2->getValue());
//			cout<<temp2->data<<endl;
			temp2 = temp2->link;
		}
		else{
			createNode(temp1->getValue());
//			cout<<temp1->data<<endl;
			temp1 = temp1->link;
		}
	}
	while(temp1!=NULL){
		createNode(temp1->data);
//		cout<<temp1->data<<endl;
		temp1 = temp1->link;
	}
	while(temp2!=NULL){
		createNode(temp2->data);
//		cout<<temp2->data<<endl;
		temp2 = temp2->link;
	}
}

int main() {
	LinkedList list1;
	LinkedList list2;
	int mainOption,loopOption=1;
	while (loopOption==1){
		cout<<"1.Add Node to List 1\n2.Add Node to List 2\n3.Merge the Nodes"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				int val;
				cout<<"Enter the value"<<endl;
				cin>>val;
				list1.createNode(val);
				list1.printNode();
				break;
			case 2:
				cout<<"Enter the value"<<endl;
				cin>>val;
				list2.createNode(val);
				list2.printNode();
				break;
			case 3:
			{
				LinkedList list3;
				list3.mergeList(list1, list2);
				list3.printNode();
				break;
			}
			default:
				cout<<"Invalid Statement"<<endl;
				break;
		}
		cout<<"Do you want to continue\n1.Continue\n2.Quit"<<endl;
		cin>>loopOption;
	}
	cout<<"Succesfully Exited!"<<endl;
	return 0;
}

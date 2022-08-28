#include <iostream>
using namespace std;

class Node{
	int coefficient,power;
	Node* link;
public:
	Node(){
		coefficient = 0;
		power = 0;
		link = NULL;
	}
	Node(int coefficient){
		this->coefficient = coefficient;
		power = 0;
		link = NULL;
	}
	Node(int coefficient,int power){
		this->coefficient = coefficient;
		this->power = power;
		link = NULL;
	}
	int getPower(){
		return this->power;
	}
	int getCoefficient(){
		return this->coefficient;
	}
	friend class LinkedList;
};

class LinkedList{
	Node* head;
public:
	LinkedList(){
		head = NULL;
	}
	void createNode(int val,int pow);
	void printPolynomial();
	void addPolynomial(LinkedList poly1,LinkedList poly2);
};

void LinkedList::createNode(int val,int pow){
//	cout<<"Hi from Create"<<endl;
	Node* newNode = new Node(val,pow);
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

void LinkedList::printPolynomial(){
//	cout<<"Hi from Print"<<endl;
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->coefficient<<"x"<<temp->power;
		if(temp->link!=NULL){
			cout<<" + ";
		}
		temp = temp->link;
	}
	cout<<" = 0"<<endl;
}

void LinkedList::addPolynomial(LinkedList poly1,LinkedList poly2){
	Node* temp1 = poly1.head;
	Node* temp2 = poly2.head;
	while(temp1!=NULL and temp2!=NULL){
		if(temp1->getPower()==temp2->getPower()){
			int sum = temp1->getCoefficient() + temp2->getCoefficient();
			createNode(sum, temp1->getPower());
			temp1 = temp1->link;
			temp2 = temp2->link;
		}
		else if (temp1->getPower()>temp2->getPower()){
			createNode(temp1->getCoefficient(), temp1->getPower());
			temp1 = temp1->link;
		}
		else{
			createNode(temp2->getCoefficient(), temp2->getPower());
			temp2 = temp2->link;
		}
	}
	while(temp1!=NULL){
		createNode(temp1->getCoefficient(), temp1->getPower());
		temp1 = temp1->link;
	}
	while(temp2!=NULL){
		createNode(temp2->getCoefficient(), temp2->getPower());
		temp2 = temp2->link;
	}
}

int main() {
	LinkedList poly1;
	poly1.createNode(9, 4);
	poly1.createNode(19, 3);
	poly1.createNode(9, 2);
	poly1.createNode(2, 1);
	poly1.createNode(2, 0);
	poly1.printPolynomial();

	LinkedList poly2;
	poly2.createNode(25, 5);
	poly2.createNode(9, 4);
	poly2.createNode(19, 3);
	poly2.createNode(19, 0);
	poly2.printPolynomial();

	LinkedList sum;
	sum.addPolynomial(poly1, poly2);
	sum.printPolynomial();
	return 0;
}

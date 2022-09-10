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
	LinkedList poly2;
	int mainOption,loopOption=1;
	int listOption = 1;
	int coef,pow;
	while (loopOption==1){
		listOption = 1;
		cout<<"1.Input Polynomial 1 \n2.Input Polynomial 2\n3. Sum of Polynomial"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				while(listOption==1){
					cout<<"Enter the coefficient"<<endl;
					cin>>coef;
					cout<<"Enter the power"<<endl;
					cin>>pow;
					poly1.createNode(coef, pow);
					cout<<"Press 0 to quit\n1 to continue"<<endl;
					cin>>listOption;
				}
				break;
			case 2:
				while(listOption==1){
					cout<<"Enter the coefficient"<<endl;
					cin>>coef;
					cout<<"Enter the power"<<endl;
					cin>>pow;
					poly2.createNode(coef, pow);
					cout<<"press 0 to quit"<<endl;
					cin>>listOption;
				}
				break;
			case 3:
			{
				LinkedList sum;
				sum.addPolynomial(poly1, poly2);
				cout<<"Sum : ";
				sum.printPolynomial();
				break;
			}
			default:
				cout<<"Invalid Statement"<<endl;
				break;
		}
		cout<<"Do you want to continue\n1.Continue\n2.Quit"<<endl;
		cin>>loopOption;
	}
	cout<<"Successfully Exited!"<<endl;
	return 0;
}

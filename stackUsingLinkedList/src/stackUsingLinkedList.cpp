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
	friend class Stack;
};

class Stack{
	Node* top;
public:
	Stack(){
		top = NULL;
	}
	void push(int val);
	void pop();
	void print();
};

void Stack::push(int val){
	Node* newNode = new Node(val);
	if(top==NULL){
		top = newNode;
		cout<<"Pushed Successfully"<<endl;
		return;
	}
	Node* temp = top;
	top = newNode;
	top->link = temp;

}

void Stack::pop(){
	if(top==NULL){
		cout<<"Stack Underflow"<<endl;
	}
	Node* temp = NULL;
	temp = top;
	top = top->link;
	cout<<"Popped Element "<<temp->data<<endl;
	delete temp;
}

void Stack::print(){
	Node* temp = top;
	while(temp!=NULL){
		cout<<temp->data<<" "<<endl;
		temp = temp->link;
	}
}

int main() {
	Stack S;
	int mainOption,loopOption=1;
	while (loopOption==1){
		cout<<"1.Push to Stack\n2.Pop from Stack"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				int val;
				cout<<"Enter the value"<<endl;
				cin>>val;
				S.push(val);
				S.print();
				break;
			case 2:
				S.pop();
				S.print();
				break;
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

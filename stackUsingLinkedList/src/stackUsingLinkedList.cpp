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
	S.push(10);
	S.push(20);
	S.push(30);
	S.push(40);
	S.print();
	S.pop();
	S.print();
	S.pop();
	S.print();
	return 0;
}

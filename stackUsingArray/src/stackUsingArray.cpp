#include <iostream>
using namespace std;


class Stack{
	int top,max;
	int array[100];
public:
	Stack(){
		max = 100;
		top = -1;
	}
	void push(int val);
	int pop();
};

void Stack::push(int val){
	if(top>=max){
		cout<<"Stack Overflow"<<endl;
		return;
	}
	top++;
	array[top] = val;
}

int Stack::pop(){
	if(top<0){
		cout<<"Stack Underflow"<<endl;
		return 0;
	}
	int pop =  array[top];
	top--;
	return pop;
}

int main() {
	Stack A;
	A.push(10);
	A.push(20);
	A.push(30);
	A.push(40);
	cout<<A.pop()<<endl;
	cout<<A.pop()<<endl;
	cout<<A.pop()<<endl;
	cout<<A.pop()<<endl;
	cout<<A.pop()<<endl;
	A.push(20);
	cout<<A.pop()<<endl;
	return 0;
}

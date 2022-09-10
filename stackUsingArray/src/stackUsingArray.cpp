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
	int mainOption,loopOption=1;
	while (loopOption==1){
		cout<<"1.Push to Stack\n2.Pop to Stack"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				int val;
				cout<<"Enter the value"<<endl;
				cin>>val;
				A.push(val);
				break;
			case 2:
				cout<<"Popped Value : ";
				cout<<A.pop()<<endl;
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

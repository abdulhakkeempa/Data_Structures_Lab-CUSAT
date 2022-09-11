// C++ program to implement a queue using an array
#include <iostream>
using namespace std;

class Queue {
	int front, rear, capacity;
	int* queue;
public:
	Queue(int c){
		front = rear = 0;
		capacity = c;
		queue = new int;
	}
	~Queue(){
		delete[] queue;
	}
	void enqueue(int data){
		if (capacity == rear) {
			cout<<"Queue is full\n";
			return;
		} else {
			queue[rear] = data;
			rear++;
		}
		return;
	}
	void dequeue(){
		if (front == rear) {
			cout<<"Queue is empty"<<endl;
			return;
		} else {
			for (int i = 0; i < rear - 1; i++) {
				queue[i] = queue[i + 1];
			}
			rear--;
		}
		return;
	}
	void display(){
		int i;
		if (front == rear) {
			cout<<"\nQueue is Empty\n";
			return;
		}
		for (i = front; i < rear; i++) {
			cout<<queue[i]<<endl;
		}
		return;
	}
};

int main(void) {
	int qSize;
	cout<<"Enter the size of the queue"<<endl;
	cin>>qSize;
	Queue q(qSize);
	int mainOption,loopOption=1;
	while (loopOption==1){
		cout<<"1.Enqueue\n2.Dequeue\n3.Display Queue"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				int val;
				cout<<"Enter the value"<<endl;
				cin>>val;
				q.enqueue(val);
				q.display();
				break;
			case 2:
				q.display();
				break;
			case 3:
				q.dequeue();
				q.display();
				break;
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

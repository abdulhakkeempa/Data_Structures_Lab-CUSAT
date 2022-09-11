#include <iostream>
using namespace std;

class QNode {
	int data;
	QNode* next;
public:
	QNode(int d) {
		data = d;
		next = NULL;
	}
	friend class Queue;
};

class Queue {
	QNode *front, *rear;
public:
	Queue(){
		front = rear = NULL;
	}
	void enqueue(int x){
		QNode* temp = new QNode(x);
		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}
	void dequeue(){
		if (front == NULL){
			cout<<"Queue Empty"<<endl;
			return;
		}
		QNode* temp = front;
		cout<<"Dequeued Element : "<<front->data<<endl;
		front = front->next;

		if (front == NULL){
			rear = NULL;
		}
		delete (temp);
	}
	void display(){
		QNode* temp = front;
		while(temp!=NULL){
			cout<<temp->data<<endl;
			temp = temp->next;
		}
	}
};

int main(){
	Queue q;
	int mainOption,loopOption=1;
	while (loopOption==1){
		cout<<"1.Enqueue\n2.Dequeue\n3.Display"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				int val;
				cout<<"Enter the value"<<endl;
				cin>>val;
				q.enqueue(val);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.display();
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



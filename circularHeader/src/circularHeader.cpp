#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void push(Node** head_ref, int data){
	Node* ptr1 = new Node();
	ptr1->data = data;
	ptr1->next = *head_ref;
	if (*head_ref != NULL) {
		Node* temp = *head_ref;
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else{
		ptr1->next = ptr1;
	}
	*head_ref = ptr1;
}

void printList(Node* head){
	Node* temp = head;
	if (head != NULL) {
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
	}
	cout << endl;
}

void deleteNode(Node** head, int key){
	if (*head == NULL){
		return;
	}
	if ((*head)->data == key && (*head)->next == *head) {
		*head = NULL;
		return;
	}
	Node *last = *head, *d;
	if ((*head)->data == key) {
		while (last->next != *head){
			last = last->next;
		}
		last->next = (*head)->next;
		*head = last->next;
		return;
	}
	while (last->next != *head && last->next->data != key) {
		last = last->next;
	}
	if (last->next->data == key) {
		d = last->next;
		last->next = d->next;
	}
	else{
		cout << "no such keyfound"<<endl;
	}
}

int main()
{
	Node* head = NULL;
	int mainOption,loopOption=1;
	cout<<"Circular Header List"<<endl;
	while (loopOption==1){
		cout<<"1.Add Node\n2.Delete Node\n3.Print Node"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				int val;
				cout<<"Enter you value"<<endl;
				cin>>val;
				push(&head, val);
				break;
			case 2:
				cout<<"Enter the delete key"<<endl;
				cin>>val;
				deleteNode(&head, val);
				cout<<"List after deletion"<<endl;
				printList(head);
				break;
			case 3:
				cout<<"List"<<endl;
				printList(head);
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

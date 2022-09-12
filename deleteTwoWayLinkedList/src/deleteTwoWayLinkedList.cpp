#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;

	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void printList(Node* node){
	Node* last;
	cout << "\nTraversal in forward direction \n";
	while (node != NULL) {
		cout << " " << node->data << " ";
		last = node;
		node = node->next;
	}

	cout << "\nTraversal in reverse direction \n";
	while (last != NULL) {
		cout << " " << last->data << " ";
		last = last->prev;
	}
	cout<<endl;
}

void deleteNode(Node** head_ref, Node* del){
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    return;
}

void deleteAllOccurOfX(Node** head_ref, int x){
    if ((*head_ref) == NULL)
        return;

    Node* current = *head_ref;
    Node* next;

    while (current != NULL) {
        if (current->data == x) {
            next = current->next;
            deleteNode(head_ref, current);
            current = next;
        }
        else
            current = current->next;
    }
}

int main(){
	Node* head = NULL;
	int mainOption,loopOption=1;
	while (loopOption==1){
		cout<<"1.Add Node\n2.Delete Node\n3.Print List"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				int val;
				cout<<"Enter your value"<<endl;
				cin>>val;
				push(&head,val);
				break;
			case 2:
				cout<<"Enter your value"<<endl;
				cin>>val;
				deleteAllOccurOfX(&head, val);
				break;
			case 3:
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

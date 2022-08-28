#include <iostream>
using namespace std;

class LinkedList;
class Node{
	int data;
	Node* link;
public:
	Node(){
		data = 0;
		link = NULL;
	}
    Node(int data){
        this->data = data;
        this->link = NULL;
    }
    friend class LinkedList;
};

class LinkedList{
	Node* head;
public:
	LinkedList(){
		head = NULL;
	}

	void addNode(int data);
	void printNodes();
	Node* searchItems(int item);
	void deleteNode(int key);
};

Node* LinkedList::searchItems(int item){
	Node* temp = head;
	while (temp !=NULL){
		if(temp->data==item){
			return temp;
		}
		temp = temp->link;
	}
	cout<<"Element not in the list"<<endl;
	return NULL;
}

void LinkedList::printNodes(){
	if(head==NULL){
		cout<<"List Overflow"<<endl;
		return;
	}
	Node* temp = head;
	while(temp !=NULL){
		if(temp->data<10){
			cout<<" ";
		}
		cout<<temp->data<<" | "<<temp->link<<" | "<<endl;
		temp = temp->link;
	}
}

void LinkedList::addNode(int data){
	Node* NewNode = new Node(data);

	if(head == NULL){
		head = NewNode;
		return;
	}
	Node* temp = head;
	while (temp->link != NULL){
		temp = temp->link;
	}
	temp->link = NewNode;
}

void LinkedList::deleteNode(int key){
	if(head->data==key){
		head = head->link;
		return;
	}
	Node* prevNode = head;
	Node* current = head->link;
	while(current!=NULL){
		if(current->data==key){
			prevNode->link = current->link;
			delete current;
			return;
		}
		prevNode = current;
		current = current->link;
	}
	cout<<"Element not found "<<endl;
}

int main() {
	LinkedList List;
	int mainOption,loopOption=1;
	while (loopOption==1){
		cout<<"1.Add Node\n2.Search Node\n3.Delete Node"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				int nodeValue;
				cout<<"Enter the value"<<endl;
				cin>>nodeValue;
				List.addNode(nodeValue);
				List.printNodes();
				break;
			case 2:
			{
				int searchKey;
				cout<<"Enter the search key"<<endl;
				cin>>searchKey;
				Node* address = List.searchItems(searchKey);
				if(address){
					cout<<"Element found with address "<<address<<endl;
				}
				break;
			}
			case 3:
				int searchKey;
				cout<<"Enter the search key "<<endl;
				cin>>searchKey;
				List.deleteNode(searchKey);
				List.printNodes();
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

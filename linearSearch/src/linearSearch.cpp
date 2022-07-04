//c++ code to implement linear search
#include <iostream>
using namespace std;

int linearSearch(int data[],int size,int search_key){
	for (int i = 0; i < size; ++i) {
		cout<<data[i]<<endl;
		if (data[i]==search_key){
			return i;
		}
	}
	return -1;
}


int main() {
	int data [] = {1,2,3,4,5,6,7};
	//extracting the size of the array
	int size = sizeof(data)/sizeof(int);
	int pos = linearSearch(data,size,10);
	if (pos!=-1){
		cout<<"Element found at "<<pos+1<<" position."<<endl;
	}
	else{
		cout<<"Element not Present"<<endl;
	}
	return 0;
}

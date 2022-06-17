//c++ code to implement binary search
#include <iostream>
using namespace std;

int binarySearch(int data[],int search_key,int low,int high){
	do{
		int mid = (low+high)/2;
		cout<<mid<<":"<<data[mid]<<endl;
		if (data[mid]==search_key){
			return mid;
		}
		else if (search_key>data[mid]){
			low = mid +1 ;
		}
		else {
			high = mid - 1;
		}
	}while(low!=high);
	return -1;
}


int main() {
	int data [] = {8,12,13,14,20,25,39,47,50};
	//extracting the size of the array
	int size = sizeof(data)/sizeof(int);
	cout<<"Size : "<<size<<endl;
	int pos = binarySearch(data,13,0,size);
	if (pos!=-1){
		cout<<"Element found at position "<<pos+1<<"."<<endl;
	}
	else{
		cout<<"Element not Present"<<endl;
	}
	return 0;
}

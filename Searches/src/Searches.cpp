#include <iostream>
using namespace std;

int linearSearch(int data[],int size,int search_key){
	for (int i = 0; i < size; ++i) {
		if (data[i]==search_key){
			return i;
		}
	}
	return -1;
}

int binarySearch(int data[],int search_key,int low,int high){
	do{
		int mid = (low+high)/2;
		if (data[mid]==search_key){
			return mid;
		}
		else if (search_key>data[mid]){
			low = mid +1 ;
		}
		else {
			high = mid;
		}
	}while(low!=high);
	return -1;
}

int ternarySearch(int arr[],int key,int length){
	int start = 0;
	int end = length - 1;
	if(key>arr[end]){
		return -1;
	}
	while (start<=end){
		int mid1 = start + (end-start)/3;
		int mid2 = end - (end-start)/3;

		if (arr[mid1]==key){
			return mid1;
		}
		else if (arr[mid2]==key){
			return mid2;
		}
		else if (key<arr[mid1]){
			end = mid1-1;
		}
		else if(key<arr[mid2]){
			start = mid1+1;
			end = mid2-1;
		}
		else{
			start = mid2+1;
		}

	}
	return -1;
}

int interpolationSearch(int arr[],int key,int length){
	int start = 0;
	int end = length-1;
	while (start<=end and key>=arr[start] and key<=arr[end]){
		int pos;
		pos = start + ((key - arr[start])*(end-start))/(arr[end]-arr[start]);
		if (arr[pos]==key){
			return pos;
		}
		else if (key>arr[pos]){
			start = pos+1;
		}
		else{
			end = pos - 1;
		}
	}
	return -1;
}

int fibonacciSearch(int data[],int searchKey,int length){
	int fib2 = 0;
	int fib1 = 1;
	int fib = fib1+fib2;
	while(fib<length){
		fib2 = fib1;
		fib1 = fib;
		fib = fib1+fib2;
	}
	int offset = -1;
	while(fib>1){
		int i = offset + fib2;
		if(data[i]<searchKey){
			fib = fib1;
			fib1 = fib2;
			fib2 = fib - fib1;
			offset = i;
		}
		else if (data[i]>searchKey){
			fib = fib2;
			fib1 = fib1 - fib;
			fib2 = fib -  fib1;
		}
		else{
			return i;
		}
	}
	if (fib==1 and data[offset+1]==searchKey){
		return offset+1;
	}
	return -1;
}

void printIndex(int pos){
	if(pos!=-1){
		cout<<"Element found at "<<pos+1<<"th position"<<endl;
	}
	else{
		cout<<"Element not found"<<endl;
	}
}

int main() {
	int userSize;
	cout<<"Enter the no of elements : ";
	cin>>userSize;

	int array[userSize];
	for (int var = 0; var < userSize; ++var) {
		cout<<"Value "<<var+1<<" : ";
		cin>>array[var];
	}

	cout<<"Input Data : ";
	for (int var = 0; var < userSize; ++var) {
		cout<<array[var]<<",";
	}
	cout<<endl;

	int exitChoice = 1;
	while(exitChoice!=2){
		int choice,position,searchKey;
		cout<<"Select the Searching Algorithm"<<endl;
		cout<<"1.Linear Search\n2.Binary Search\n3.Ternary Search\n4.Interpolation Search\n5.Fibonacci Search\n";
		cin>>choice;
		cout<<"Search Key : ";
		cin>>searchKey;
		switch (choice) {
			case 1:
				position = linearSearch(array, userSize, searchKey);
				printIndex(position);
				break;
			case 2:
				position = binarySearch(array, searchKey, 0, userSize-1);
				printIndex(position);
				break;
			case 3:
				position = ternarySearch(array, searchKey, userSize);
				printIndex(position);
				break;
			case 4:
				position = interpolationSearch(array, searchKey, userSize);
				printIndex(position);
				break;
			case 5:
				position = fibonacciSearch(array, searchKey, userSize);
				printIndex(position);
				break;
			default:
				cout<<"Invalid Option";
				break;
		}
		cout<<"1.Continue\n2.Exit"<<endl;
		cin>>exitChoice;
	}
	cout<<"Successfully Exited"<<endl;
	return 0;
}

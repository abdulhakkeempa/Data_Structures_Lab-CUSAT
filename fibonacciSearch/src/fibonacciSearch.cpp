//============================================================================
// Name        : fibonacciSearch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int fibonacciSearch(int data[],int searchKey,int length){
	//fibanocci digits
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


int main() {
	int data[] = {10, 13, 15, 26, 28, 50, 56, 88, 94, 127, 159, 356, 480, 567, 689, 699, 780, 850, 956, 995};
	int length = sizeof(data)/sizeof(data[0]);
	int index = fibonacciSearch(data, 50, length);
	if(index!=-1){
		cout<<"Element found at "<<index+1<<"th position"<<endl;
	}
	else{
		cout<<"Element not found"<<endl;
	}
	return 0;
}

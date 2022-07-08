//============================================================================
// Name        : selectionSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void printArray(int* data,int length);


void bubbleSort(int* data,int length){
	for (int i = 0; i < length-1; ++i) {
		for (int j = 0; j < length-i-1; ++j) {

			if (data[j]>data[j+1]){
				int temp;
				temp = data[j+1];
				data[j+1]=data[j];
				data[j]=temp;
			}
		}
		cout<<"Pass "<<i<<" : ";
		printArray(data, length);
		cout<<endl;
	}
}

void printArray(int* data,int length){
	for (int var = 0; var < length; ++var) {
		cout<<data[var]<<" ";
	}
}

int main() {
	int array[] = {7,4,10,8,3,1};
	int length = sizeof(array)/sizeof(array[0]);
	bubbleSort(array, length);
	printArray(array, length);
	return 0;
}

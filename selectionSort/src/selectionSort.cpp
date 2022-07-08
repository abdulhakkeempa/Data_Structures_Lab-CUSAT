//============================================================================
// Name        : selectionSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void selectionSort(int* data,int length){
	for (int i = 0; i < length; ++i) {
		for (int j = i+1; j < length; ++j) {

			if (data[i]>data[j]){
				int temp;
				temp = data[j];
				data[j]=data[i];
				data[i]=temp;
			}
		}
	}
}

int main() {
	int array[] = {5,6,1,2,4,0,9,8};
	int length = sizeof(array)/sizeof(array[0]);
	selectionSort(array, length);
	for (int var = 0; var < length; ++var) {
		cout<<array[var]<<" ";
	}
	return 0;
}

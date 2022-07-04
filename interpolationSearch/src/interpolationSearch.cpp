//============================================================================
// Name        : interpolationSearch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int interpolationSearch(int arr[],int key,int length){
	int start = 0;
	int end = length-1;
	while (start<=end and key>=arr[start] and key<=arr[end]){
		int pos;
		pos = start + ((key - arr[start])*(end-start))/(arr[end]-arr[start]);
		cout<<"Pos : "<<pos<<endl;
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

int main() {
	int data[] = {10, 13, 15, 26, 28, 50, 56, 88, 94, 127, 159, 356, 480, 567, 689, 699, 780, 850, 956, 995};
	int length = sizeof(data)/sizeof(data[0]);
	int index = interpolationSearch(data, 98, length);
	if(index!=-1){
		cout<<"Element found at "<<index+1<<"th position"<<endl;
	}
	else{
		cout<<"Element not found"<<endl;
	}
	return 0;
}

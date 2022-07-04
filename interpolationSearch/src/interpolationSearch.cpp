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
	int data[] = {10,20,30,40,50,60,70,75,89,98};
	int length = sizeof(data)/sizeof(data[0]);
	int index = interpolationSearch(data, 100, length);
	if(index!=-1){
		cout<<"Element found at "<<index+1<<"th position"<<endl;
	}
	else{
		cout<<"Element not found"<<endl;
	}
	return 0;
}

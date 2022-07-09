#include <iostream>
using namespace std;

void printArray(int* data,int length){
	for (int var = 0; var < length; ++var) {
		cout<<data[var]<<" ";
	}
}

void insertSort(int* data,int length){
	int key;
	int j;
	for (int i = 1; i < length; ++i) {
		key = data[i];
		j = i-1;
		while(j>=0 and data[j]>key){
			data[j+1] = data[j];
			j = j-1;
		}
		data[j+1] = key;
	}
}

int main() {
	int array[] = {7,4,10,8,3,1};
	int length = sizeof(array)/sizeof(array[0]);
	insertSort(array, length);
	printArray(array, length);
	return 0;
}

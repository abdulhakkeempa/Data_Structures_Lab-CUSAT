#include <iostream>
using namespace std;

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

void selectionSort(int* data,int length){
	for (int i = 0; i < length-1; ++i) {
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

void merge(int* array,int begin,int mid,int end){
	int i,j,k;
	int sortedArray[end];
	i = begin;
	j = mid+1;
	k = begin;
	while (i<=mid and j<=end){
		if (array[i]<=array[j]){
			sortedArray[k] = array[i];
			i++;
		}
		else{
			sortedArray[k] = array[j];
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=end){
			sortedArray[k] = array[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid){
			sortedArray[k] = array[i];
			i++;
			k++;
		}
	}
	for (int var = begin; var <= end; ++var) {
		array[var] = sortedArray[var];
	}
}


void mergeSort(int* array,int begin,int end){
	if(begin==end){
		return;
	}
	int mid = (begin+end)/2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid+1, end);
	merge(array,begin,mid,end);
}

void printArray(int* data,int length){
	for (int var = 0; var < length; ++var) {
		cout<<data[var]<<" ";
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
		int choice;
		cout<<"Select the Sorting Algorithm"<<endl;
		cout<<"1.Selection Sort\n2.Bubble Sort\n3.Insertion Sort\n4.Merge Sort\n";
		cin>>choice;
		switch (choice) {
			case 1:
				selectionSort(array, userSize);
				printArray(array, userSize);
				break;
			case 2:
				bubbleSort(array, userSize);
				printArray(array, userSize);
				break;
			case 3:
				insertSort(array, userSize);
				printArray(array, userSize);
				break;
			case 4:
				mergeSort(array, 0, userSize-1);
				printArray(array, userSize);
				break;
			default:
				cout<<"Invalid Option";
				break;
		}
		cout<<"\n1.Continue\n2.Exit"<<endl;
		cin>>exitChoice;
	}
	cout<<"Successfully Exited"<<endl;

	return 0;
}

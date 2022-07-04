#include <iostream>
using namespace std;

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


int main() {
	int data [] = {2,3,5,6,8,9,12,13,14};
	int length = sizeof(data)/sizeof(data[0]);
	int index = ternarySearch(data, 14, length);
	if(index!=-1){
		cout<<"Element found at "<<index+1<<"th position"<<endl;
	}
	else{
		cout<<"Element not found"<<endl;
	}
	return 0;
}

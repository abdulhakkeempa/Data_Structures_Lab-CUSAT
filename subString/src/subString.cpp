#include <iostream>
#include <cstring>
using namespace std;

void subStringExtraction(char* str,int len){
	for (int i = 0; i < len; ++i) {
		for (int j = i+1; j <= len; ++j) {
			for (int k = i; k < j; ++k) {
				cout<<str[k]<<" ";
			}
			cout<<endl;
		}
	}
}

int main() {
	char str[20];
	cout<<"Enter the string"<<endl;
	cin>>str;
	cout<<"The Substrings of "<<str<<" are "<<endl;
	subStringExtraction(str, strlen(str));
	return 0;
}

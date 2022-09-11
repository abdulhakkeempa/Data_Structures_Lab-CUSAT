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

void patternMatching(char* str,char *pattern){
	int strLen = strlen(str);
	int pattLen = strlen(pattern);
	for (int i = 0; i < strLen-pattLen; ++i) {
		int j;
		for (j = 0; j < pattLen; ++j) {
			if(str[i+j]!=pattern[j]){
				break;
			}
		}
		if(j==pattLen){
			cout<<"Pattern found at "<<i<<endl;
		}
	}
}

int main() {
	char str[20],pattern[10];
	cout<<"Enter the string"<<endl;
	cin>>str;
//	cout<<"The Substrings of "<<str<<" are "<<endl;
//	subStringExtraction(str, strlen(str));
	cout<<"Enter the pattern"<<endl;
	cin>>pattern;
	patternMatching(str, pattern);
	return 0;
}

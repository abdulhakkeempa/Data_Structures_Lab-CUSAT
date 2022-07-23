//============================================================================
// Name        : saddlePoint.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool saddlePoint(int **data,int rowSize,int colSize){
	int minElement,colIndex;
	for (int i = 0; i < rowSize; ++i) {
		minElement = data[i][0];
		colIndex = 0;
		for (int j = 0; j < colSize; ++j) {
			if (minElement>data[i][j]) {
				minElement = data[i][j];
				colIndex = j;
			}
		}
		int k;
		bool found=false;
		for (k = 0; k < rowSize; ++k) {
			if (minElement<data[k][colIndex]){
				found = true;
				break;
			}
		}
		if (!found){
			cout<<"Saddle Point is "<<minElement<<endl;
			return true;
		}
	}
	return false;
}



int main() {
	int **data;
	int row,col;
	cout<<"Enter the no of row : ";
	cin>>row;
	cout<<"Enter the no of column : ";
	cin>>col;
	data = new int *[row];
	for (int i = 0; i < row; ++i) {
		data[i] = new int [col];
	}
	cout<<"Enter the values"<<endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin>>data[i][j];
		}
	}
    if(!saddlePoint(data, row, col)){
    	cout<<"No Saddle Point Found"<<endl;
    }
	return 0;
}

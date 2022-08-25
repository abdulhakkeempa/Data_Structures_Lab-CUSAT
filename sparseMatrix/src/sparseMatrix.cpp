#include <iostream>
using namespace std;

class matrix{
	int **data;
	int row,col;
public:
	void allocate(){
		cout<<"Enter the no of non zero values in matrix"<<endl;
		cin>>row;
		col = 3;
		data = new int*[row];
		for (int i = 0; i < row; ++i) {
			data[i] = new int[col];
		}
	}
	void addEntries(){
		cout<<"Enter the elements in the matrix"<<endl;
		for (int i = 0; i < row; ++i) {
			cout<<"Row - 1";
			for (int j = 0; j < col; ++j) {
				cin>>data[i][j];
			}
		}
	}
	void printMatrix(){
		cout<<"Row 		Coloumn		Value"<<endl;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				cout<<data[i][j]<<"  ";
			}
			cout<<endl;
		}
	}
	void transpose(){
		int temp;
		int j;
		for (int i = 0; i < row; ++i) {
			if(data[i][0] != data[i][1]){
				j = 0;
				temp = data[i][0];
				data[i][0] = data[i][1];
				data[i][1] = temp;
			}
		}
	}
	friend void addMatrix(const matrix &a,const matrix&b);
};

void addMatrix(const matrix &a,const matrix&b){

}

int main() {
	matrix a;
	a.allocate();
	a.addEntries();
	a.printMatrix();
	a.transpose();
	a.printMatrix();
	return 0;
}

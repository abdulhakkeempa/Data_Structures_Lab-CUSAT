#include <iostream>
using namespace std;

class matrix{
	int **data;
	int sparseRow,sparseCol;
	int rowSize,colSize;
public:
	matrix(){
		sparseCol = 3;
	}
	matrix(int sR,int r,int c){
		sparseRow = sR;
		sparseCol = 3;
		rowSize = r;
		colSize = c;
		data = new int*[sparseRow];
		for (int i = 0; i < sparseRow; ++i) {
			data[i] = new int[sparseCol];
		}
	}
	void create(int sR,int r,int c){
		sparseRow = sR;
		sparseCol = 3;
		rowSize = r;
		colSize = c;
		data = new int*[sparseRow];
		for (int i = 0; i < sparseRow; ++i) {
			data[i] = new int[sparseCol];
		}
	}
	void insert(int i,int j,int val){
		data[i][j] = val;
	}
	void allocate(){
		cout<<"Enter the row size of the matrix"<<endl;
		cin>>rowSize;
		cout<<"Enter the colomn size of the matrix"<<endl;
		cin>>colSize;
		cout<<"Enter the no of non zero values in matrix"<<endl;
		cin>>sparseRow;
		data = new int*[sparseRow];
		for (int i = 0; i < sparseRow; ++i) {
			data[i] = new int[sparseCol];
		}
	}
	void addEntries(){
		cout<<"Enter the elements in the matrix"<<endl;
		for (int i = 0; i < sparseRow; ++i) {
			cout<<"Row - "<<i+1<<endl;
			for (int j = 0; j < sparseCol; ++j) {
				cin>>data[i][j];
			}
		}
	}
	void printMatrix(){
		cout<<"Row 		Coloumn		Value"<<endl;
		for (int i = 0; i < sparseRow; ++i) {
			for (int j = 0; j < sparseCol; ++j) {
				cout<<data[i][j]<<"  ";
			}
			cout<<endl;
		}
	}
	void transpose(){
		matrix trans;
		trans.create(sparseRow, colSize, rowSize);
		for (int i = 0; i < sparseRow; ++i) {
				trans.insert(i,0,data[i][1]);
				trans.insert(i,1,data[i][0]);
				trans.insert(i,2,data[i][2]);
		}
		trans.printMatrix();
	}
	friend void addMatrix(const matrix &a,const matrix &b);
};

void addMatrix(const matrix &a,const matrix&b){
	if(a.rowSize!=b.rowSize and a.colSize!=b.colSize){
		cout<<"Addition not possible"<<endl;
		return;
	}
	matrix sum;
	sum.create(a.sparseRow, a.rowSize, a.colSize);
	int aNum=0;
	int bNum=0;
	while(aNum < a.sparseRow and bNum < b.sparseRow){
		if(a.data[aNum][0]>b.data[bNum][0] or (a.data[aNum][0]==b.data[bNum][0] and a.data[aNum][1]>b.data[bNum][1])){
			sum.insert(b.data[bNum][0],b.data[bNum][1],b.data[bNum][2]);
			bNum++;
		}
        else if (a.data[aNum][0] < b.data[bNum][0] or (a.data[aNum][0] == b.data[bNum][0] and a.data[aNum][1] < b.data[bNum][1])){
            sum.insert(a.data[aNum][0],a.data[aNum][1],a.data[aNum][2]);
            aNum++;
        }
        else
        {
            int addedval = a.data[aNum][2] +
                         b.data[aNum][2];

            if (addedval != 0)
                sum.insert(a.data[aNum][0],
                              a.data[aNum][1],
                              addedval);
            // then insert
            aNum++;
            bNum++;
        }
	}
    while (aNum < a.sparseRow){
        sum.insert(a.data[aNum][0],
                      a.data[aNum][1],
                      a.data[aNum][2]);
        aNum++;
    }

    while (bNum < b.sparseRow){
        sum.insert(b.data[bNum][0],
                      b.data[bNum][1],
                      b.data[bNum][2]);
        bNum++;
    }
	cout<<"Hello"<<endl;
	sum.printMatrix();
}

int main() {
	matrix a;
	int mainOption,loopOption=1;
	while (loopOption==1){
		cout<<"1.Add Matrix\n2.Transpose Matrix\n3.Sum of Two Matrix"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				a.allocate();
				a.addEntries();
				a.printMatrix();
				cout<<"Matrix you have entered"<<endl;
				break;
			case 2:
				a.transpose();
				break;
			case 3:
			{
				cout<<"Enter one more matrix"<<endl;
				matrix b;
				b.allocate();
				b.addEntries();
				addMatrix(a, b);
				break;
			}
			default:
				cout<<"Invalid Statement"<<endl;
				break;
		}
		cout<<"Do you want to continue\n1.Continue\n2.Quit"<<endl;
		cin>>loopOption;
	}
	cout<<"Succesfully Exited!"<<endl;
	return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

void magicMatrix(int n)
{
	int magicMatrix[n][n];
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        magicMatrix[i][j]=0;
	    }
	}
	int i = n / 2;
	int j = n - 1;

	for (int num = 1; num <= n * n;) {
		if (i == -1 && j == n){
			j = n - 2;
			i = 0;
		} else {
			if (j == n){
				j = 0;
			}
			if (i < 0){
				i = n - 1;
			}
		}
		if (magicMatrix[i][j]){
			j = j - 2;
			i++;
			continue;
		} else {
			magicMatrix[i][j] = num++;
		}
		j++;
		i--;
	}

    cout<<"The Generated Magic Square is "<<endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++){
			cout<<setw(4)<<magicMatrix[i][j]<<"  ";
		}
		cout<<endl;
	}
}

bool evenOrOdd(int n){
    if (n%2==0){
        return true;
    }
    return false;
}

int main() {
    int userSize;
    cout<<"Enter the size of the matrix"<<endl;
    cin>>userSize;
	  if(evenOrOdd(userSize)){
	    cout<<"Only possible for odd numbers"<<endl;
	  } else {
	    magicMatrix(userSize);
	  }
	  return 0;
}

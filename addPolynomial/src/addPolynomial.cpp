#include <iostream>
using namespace std;

void printPolynomial(int* polynomial,int degree);

void addPolynomial(int* polynomial1,int* polynomial2,int degree1,int degree2){
	int newDegree = max(degree1,degree2);
	int *sum = new int[newDegree+1];
	int i;
	for (i = 0; i <= min(degree1,degree2); ++i) {
		sum[i] = polynomial1[i]+polynomial2[i];
	}
	if(degree1==degree2){
		printPolynomial(sum, newDegree);
		return;
	}
	else if(degree1>degree2){
		for (int var = i; var <= degree1; ++var) {
			sum[var] = polynomial1[var];
		}
		printPolynomial(sum, newDegree);
		return;
	}
	else{
		for (int var = i; var <= degree2; ++var) {
			sum[var] = polynomial2[var];
		}
		printPolynomial(sum, newDegree);
		return;
	}
}

int max(int num1,int num2){
	if (num1>num2){
		return num1;
	}
	return num2;
}

int min(int num1,int num2){
	if (num1>num2){
		return num2;
	}
	return num1;
}

void printPolynomial(int* polynomial,int degree){
    int var;
	for (var = degree; var > 0; var--) {
	    if(polynomial[var]!=0){
		cout<<polynomial[var]<<"x"<<var;
		cout<<" + ";
	    }
	}
	cout<<polynomial[var];
}

int main() {
	int array1[] = {5,4,10,11,25};
	int array2[] = {25,4,10,11,25};
	addPolynomial(array2,array1, 4,4);
	return 0;
}

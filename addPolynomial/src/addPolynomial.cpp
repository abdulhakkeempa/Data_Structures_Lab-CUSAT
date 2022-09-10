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
	cout<<endl;
}

int main() {
	int degree1,degree2;
	cout<<"Welcome"<<endl;
	cout<<"Enter the degree of first polynomial"<<endl;
	cin>>degree1;
	int *poly1 = new int[degree1+1];
	for (int var = degree1; var >=0;var--) {
		cout<<"Coefficient of x"<<var<<" : ";
		cin>>poly1[var];
	}
	cout<<"Polynomial 1 : ";
	printPolynomial(poly1, degree1);
	cout<<"Enter the degree of second polynomial"<<endl;
	cin>>degree2;
	int *poly2 = new int[degree2+1];
	for (int var = degree2; var >=0;var--) {
		cout<<"Coefficient of x"<<var<<" : ";
		cin>>poly2[var];
	}
	cout<<"Polynomial 2 : ";
	printPolynomial(poly2, degree2);
	cout<<"Sum : ";
	addPolynomial(poly1, poly2, degree1, degree2);
	cout<<"Succesfully Exited!"<<endl;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

void replaceStr(string &str){
	string replace;
	int loc;
	cout<<"Enter the replacing text"<<endl;
	cin>>replace;
	cout<<"Enter the location"<<endl;
	cin>>loc;

	str.replace(loc,replace.length(),replace);
}
void insertStr(string &str){
	string insert;
	int loc;
	cout<<"Enter the text to insert"<<endl;
	cin>>insert;
	cout<<"Enter the location"<<endl;
	cin>>loc;
	str.insert(loc, insert);

}
void deleteStr(string &str){
	int startLoc,endLoc;
	cout<<"Enter the start location"<<endl;
	cin>>startLoc;
	cout<<"Enter the end location"<<endl;
	cin>>endLoc;
	str.erase(startLoc,(endLoc-startLoc)+1);
}

int main() {
	string str;
	cout<<"Enter your string"<<endl;
	cin>>str;
	int mainOption,loopOption=1;
	while (loopOption==1){
		cout<<"1.Insert String\n2.Replace String\n3.Delete String"<<endl;
		cin>>mainOption;
		switch (mainOption) {
			case 1:
				insertStr(str);
				cout<<str<<endl;
				break;
			case 2:
				replaceStr(str);
				cout<<str<<endl;
				break;
			case 3:
				deleteStr(str);
				cout<<str<<endl;
				break;
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

#include <iostream>
#include <cstring>
using namespace std;

class Strings{
	char *str;
	int length;
public:
	Strings(){
		length=0;
		str = new char[length+1];
	}
	Strings(char *txt){
		length = strlen(txt);
		str = new char [length+1];
	}
	void insertString(char* insertText);
};

void Strings::insertString(char* insertText){
	int newLen = strlen(insertText);
	Strings tempString;

}

int main() {

	return 0;
}

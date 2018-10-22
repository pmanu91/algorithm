 
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string str;

	getline(cin, str);
	
	int length = str.length();
	int spaceCount = 0;
	int charCount = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] == ' ')
			spaceCount++;
		else {
			charCount++;
			str[i - spaceCount] = str[i];
		}
	}
	str[charCount] = '\0';
	//str.resize(charCount);

	cout << str << endl;
}
 
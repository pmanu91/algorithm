 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string str;
	string reverseStr = "";

	getline(cin, str);

	int length = str.length();

	for (int i = 0; i < length; i++) {
		reverseStr += str[length - i - 1];
	}

	cout << reverseStr << endl;
}
 
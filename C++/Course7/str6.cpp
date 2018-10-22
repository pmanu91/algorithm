 
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string subStr;

	getline(cin, str);
	getline(cin, subStr);

	int str_len = str.length();
	int subStr_len = subStr.length();
	
	for (int i = 0; i < str_len - 1; i++) {

		int k = 0;
		while (i + k < str_len - 1 && k < subStr_len - 1 && str[i + k] == subStr[k]) {
			k++;
		}
		if (subStr_len - 1 == k) {
			cout << "YES" << endl;
			return 0;
		}
	}
	

	cout << "NO" << endl;
	return 0;
}
 
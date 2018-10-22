 
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	getline(cin, str);

	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - i - 1]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
 
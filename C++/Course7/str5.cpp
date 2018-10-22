 
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string d_str(int decimal) {
	string result = "";
	char temp[10000];
	int i = 0;
	while (decimal > 0) {
		temp[i] = decimal % 10;
		decimal /= 10;
		i++;
	}
	for (int k = i - 1; k >= 0; k--) {
		result += temp[k] + 48;	// 0 48
	}
	return result;
}

int main() {
	string str;
	string result = "";

	getline(cin, str);

	char c = str[0];
	int count = 1;
	for (int i = 1; i < str.length(); i++) {
		if (c == str[i])
			count++;
		else {
			if (count != 1) {
				result += d_str(count);
			}
			
			result += c;
			count = 1;
			c = str[i];
		}

		if (i == str.length() - 1) {
			if (count != 1) {
				result += d_str(count);
			}

			result += c;
			count = 1;
			c = str[i];
		}
	}

	cout << result << endl;
}
 
 
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	char str[1000];

	//printf("%d %d %d %d", 'a','z','A','Z');
	// a   z  A  Z
	// 97 122 65 90

	cin.getline(str, 1000);
	
	int length = strlen(str);

	for (int i = 0; i < length; i++) {
		if (str[i] >= 97 && str[i] <= 122) {
			str[i] -= 32;
		}
		else if (str[i] >= 65 && str[i] <= 90) {
			str[i] += 32;
		}
	}

	cout << str << endl;
}
 
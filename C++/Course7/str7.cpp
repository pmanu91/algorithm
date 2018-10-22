#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<string> strArr;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		strArr.push_back(temp);
	}

	sort(strArr.begin(), strArr.end());

	for (int i = 0; i < n; i++) {
		cout << strArr[i] << endl;
	}

	return 0;
}
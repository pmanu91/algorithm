 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
vector<int> box;

bool search(int number, int start, int end) {
	if (end < start) return false;
	int mid = (start + end) / 2;
	if (box[mid] == number) {
		return true;
	}
	else if (box[mid] > number) {
		search(number, start, mid - 1);
	}
	else if (box[mid] < number) {
		search(number, mid + 1, end);
	}
}

int main() {
	cin >> n;
	
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		box.push_back(temp);
	}

	// ���ڹڽ��ȿ� ���ڸ� ����
	sort(box.begin(), box.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int number;
		cin >> number;
		cout << search(number, 0, n-1) << endl;
	}
	
}
 
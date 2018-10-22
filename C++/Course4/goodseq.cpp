#include <iostream>

using namespace std;
bool foundAnswer = false;

void printSeq(int n, int arr[100]) {
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
	cout << endl;
}

void seq(int n, int arr[100], int k) {
	if (foundAnswer) return;
	if (k >= n) {
		printSeq(n, arr);
		foundAnswer = true;
		return;
	}

	for (int i = 0; i * 2 < k; i++) {
		bool isDuplicated = true;
		for (int j = k; j >= k - i; j--) {
			if (arr[j] != arr[j - i - 1]) {
				isDuplicated = false;
				break;
			}
		}
		if (isDuplicated) return;
	}

	if (arr[k] != 1) {
		arr[k + 1] = 1;
		seq(n, arr, k+1);
	}

	if (arr[k] != 2) {
		arr[k + 1] = 2;
		seq(n, arr, k + 1);
	}

	if (arr[k] != 3) {
		arr[k + 1] = 3;
		seq(n, arr, k + 1);
	}
}

int main() {
	int n;
	int arr[100];

	cin >> n;

	arr[0] = 1;
	seq(n, arr, 0);
	arr[0] = 2;
	seq(n, arr, 0);
	arr[0] = 3;
	seq(n, arr, 0);
}

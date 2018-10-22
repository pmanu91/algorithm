#include <iostream>

using namespace std;

void printBinary(int n, int arr[40]) {
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
	cout << endl;
}

void putBinary(int n, int k, int arr[40], int idx) {
	if (k < 0) return;
	if (n - idx < k) return;
	if (idx > n-1) {
		if (k == 0){
			printBinary(n, arr);
		}
		return;
	}

	arr[idx] = 1;
	putBinary(n, k-1, arr, idx+1);
	
	arr[idx] = 0;
	putBinary(n, k, arr, idx + 1);

}


int main() {
	int n, k;
	int arr[40], idx = 0;
	
	cin >> n >> k;

	putBinary(n, k, arr, idx);
}

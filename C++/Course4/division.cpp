#include <iostream>

using namespace std;

int hapCount = 0;

void printHap(int arr[30], int count) {
	for (int i = 0; i < count; i++) {
		if (i != count - 1)
			cout << arr[i] << '+';
		else
			cout << arr[i] << endl;
	}

}

void division(int n, int hap, int arr[30], int idx) {
	int num;
	if (hap > n) return;
	if (hap == n) {
		printHap(arr, idx);
		hapCount++;
		return;
	}

	if (idx == 0) 
		num = n - 1;
	else 
		num = arr[idx - 1];
	
	for (int i = num; i > 0; i--)
	{
		arr[idx] = i;
		division(n, hap + i, arr, idx + 1);
	}
	
}

int main() {
	int n;
	int arr[30], idx = 0;
	int hap = 0;

	cin >> n;

	division(n, hap, arr, idx);
	cout << hapCount << endl;
}

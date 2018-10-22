#include <iostream>
#include <cmath>

using namespace std;

int solutinCount = 0;
void printCowLine(int n, char operation[20]) {
	for (int i = 1; i <= n; i++) {
		if (i != n) {
			cout << i << ' ' << operation[i] << ' ';
		}
		else
			cout << i;
	}
	cout << endl;
}

int calcSum(int n, int number[20], char operation[20]) {
	int sum = number[0];
	for (int i = 1; i < n; i++) {
		if (number[i] != 0) {
			if (operation[i] == '+') {
				sum += number[i];
			}
			else if (operation[i] == '-') {
				sum -= number[i];
			}
		}
	}
	return sum;
}

void printNumber(int n, int number[20]) {
	for (int i = 0; i < n; i++) {
		cout << number[i] << " ";
	}
	cout << endl;

}

int getDigit(int n) {
	int digit = 1;
	while (1) {
		n = n / 10;
		if (n >= 1) digit++;
		else return digit;
	}
}

// k : idx
// p : . repeat count
void arrangeCow(int n, char operation[20], int number[20], int k, int p) {
	if (k > n) {
		if (calcSum(n, number, operation) == 0) {
			if (operation[k-1] != '+') return;
			//printNumber(n, number);
			printCowLine(n, operation);
			solutinCount++;
			return;
		}
		else {
			return;
		}
	}

	int tempValue = 0;
	int digit = 0;
	for (int i = 0; i <= p; i++) {
		tempValue += (k-i) * pow(10, digit * i);
		digit = getDigit(k-i);
		number[k - i - 1] = 0;
	}
	number[k - p - 1] = tempValue;

	operation[k] = '+';
	arrangeCow(n, operation, number, k + 1, 0);

	operation[k] = '-';
	arrangeCow(n, operation, number, k + 1, 0);

	operation[k] = '.';
	arrangeCow(n, operation, number, k + 1, p + 1);

}

int main() {
	int n;
	int number[20];
	char operation[20];
	
	cin >> n;
	// 1~n;

	arrangeCow(n, operation, number, 1, 0);
	
	cout << solutinCount << endl;
}

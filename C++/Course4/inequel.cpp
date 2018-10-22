#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MAX[10] = {0,0,0,0,0,0,0,0,0,0};
int MIN[10] = {9,9,9,9,9,9,9,9,9,9};
int k;
char ineq[10];

void compareMax(int number[10], int len);
void compareMin(int number[10], int len);
void inequel(int number[10], int idx, bool visited[10]);

int main() {
	int number[10]; // 0 ~ 9
	bool visited[10];

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> ineq[i];
	}

	for (int i = 0; i <= 9; i++) {
		visited[i] = true;
		number[0] = i;
		inequel(number, 1, visited);
		visited[i] = false;
	}

	// print max
	for (int i = 0; i <= k; i++) {
		cout << MAX[i];
	}
	cout << endl;

	// print min
	for (int i = 0; i <= k; i++) {
		cout << MIN[i];
	}
	cout << endl;

}

void inequel(int number[10], int idx, bool visited[10]) {
	if (idx > k) {
		compareMax(number, k + 1);
		compareMin(number, k + 1);
		return;
	}

	int prevNum = number[idx - 1];

	for (int i = 0; i <= 9; i++) {
		// �� ���� ����� ���� �ƴϸ�
		if (!visited[i]) {
			if (ineq[idx] == '<') {
				if (prevNum >= i) continue;
			}
			else {
				if (prevNum <= i) continue;
			}
			// ���� ������ �����ϸ� ���� ���� ����
			visited[i] = true;
			number[idx] = i;
			inequel(number, idx + 1, visited);
			visited[i] = false;
		}
	}
}

void compareMax(int number[10], int len) {
	for (int i = 0; i < len; i++) {
		if (number[i] < MAX[i]) return;
	}
	
	for (int i = 0; i < len; i++) {
		MAX[i] = number[i];
	}
}

void compareMin(int number[10], int len) {
	for (int i = 0; i < len; i++) {
		if (number[i] > MIN[i]) return;
	}

	for (int i = 0; i < len; i++) {
		MIN[i] = number[i];
	}
}

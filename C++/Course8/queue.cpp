#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;

struct Queue {
	int data[MAX];
	int f, r;
	int capacity = 0;
	int elementCnt = 0;
	
	void create(int size) {
		f = 0;
		r = 0;
		capacity = size;
	}

	void push(int n) {
		if (elementCnt >= capacity) {
			cout << "Overflow" << endl;
		}
		else {
			data[r] = n;
			r = (r + 1) % MAX;
			elementCnt++;
		}
	}

	void pop() {
		if (elementCnt <= 0) {
			cout << "Underflow" << endl;
		}
		else {
			data[f] = 0;
			f = (f + 1) % MAX;
			elementCnt--;
		}
	}

	int front() {
		if (elementCnt <= 0) {
			cout << "NULL" << endl;
			return -1;
		}
		else {
			return data[f];
		}
	}

	int size() {
		return elementCnt;
	}
};

int main() {
	vector<pair<int, int> > command;
	int n, m;
	cin >> n >> m;

	Queue q;
	q.create(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a;

		if (a == 1) {
			cin >> b;
			command.push_back({ a, b });
		}
		else {
			command.push_back({ a,0 });
		}
	}

	for (int i = 0; i < m; i++) {
		int cmd = command[i].first;
		if (cmd == 1) {
			q.push(command[i].second);
		}
		else if (cmd == 2) {
			q.pop();
		}
		else if (cmd == 3) {
			int front = q.front();
			if (front != -1) {
				cout << front << endl;
			}
		}
	}

}
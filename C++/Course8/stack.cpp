 
#include <iostream>
#include <vector>

using namespace std;

// create()
// push()
// pop()
// top()
// size()

int n, m;

struct Stack {
	int data[100];
	int len = 0;
	int capacity = 0;

	void create(int size) {
		capacity = size;
	}

	void push(int num) {
		if (len >= capacity) {
			cout << "Overflow" << endl;
		}
		else {
			data[len++] = num;
		}
	}

	void pop() {
		if (len <= 0) {
			cout << "Underflow" << endl;
		}
		else {
			data[len--] = 0;
		}
	}

	int top() {
		if (len <= 0) {
			cout << "NULL" << endl;
			return NULL;
		}
		return data[len-1];
	}

	int size() {
		return len;
	}
};

int main() {
	vector<pair<int, int> > command;
	cin >> n >> m;
	
	Stack s;
	s.create(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a;

		if (a == 1) {
			cin >> b;
			command.push_back({a, b});
		}
		else {
			command.push_back({a,0});
		}
	}

	for (int i = 0; i < m; i++) {
		switch (command[i].first) {
			case 1:
				s.push(command[i].second);
				break;
			case 2:
				s.pop();
				break;
			default:
				int top = s.top();
				if (top != NULL)
					cout << top << endl;
				break;
		}
	}
}

 
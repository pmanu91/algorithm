
 

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 99999;
bool visited[MAX + 1] = { false };
int n;

void bfs(int start) {
	queue<pair<int, int> > q;

	q.push({1, 0});
	visited[1] = true;

	while (!q.empty()) {
		int k = q.front().first;
		int count = q.front().second;
		q.pop();
		
		// success
		if (k == n) {
			cout << count << endl;
			return;
		}

		// mul *2
		if (k*2 <= MAX) if (!visited[k*2]) {
			q.push({k*2, count + 1});
			visited[k * 2] = true;
		}
		// div /3
		if (k / 3 != 0) if (!visited[k/3]) {
			q.push({k/3, count + 1});
			visited[k / 3] = true;
		}
	}
}

int main() {
	cin >> n;

	bfs(1);
}
 
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 26;
const int MAX_E = 100;

int N, E;
char startNode;
int a[MAX_N + 1][MAX_N + 1];
bool visit1[MAX_N + 1] = { false };
bool visit2[MAX_N + 1] = { false };

void dfs(int x) {
	visit1[x] = true;
	printf("%c", x + 64);

	for (int i = 1; i <= MAX_N; i++) {
		if (a[x][i] == 1 && !visit1[i]) {
			dfs(i);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visit2[x] = true;
	
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		printf("%c", f + 64);

		for (int i = 1; i <= MAX_N; i++) {
			if (a[f][i] == 1 && !visit2[i]) {
				q.push(i);
				visit2[i] = true;
			}
		}
	}
}

int main() {
	// 'A' -> 65
	cin >> N >> E;
	
	for (int i = 0; i < E; i++) {
		char v1, v2;
		cin >> v1 >> v2;
		v1 -= 64; v2 -= 64; // 'A' -> 1
		a[v1][v2] = a[v2][v1] = 1;
	}

	cin >> startNode;

	dfs(startNode - 64);
	cout << endl;
	bfs(startNode - 64);
	cout << endl;
}
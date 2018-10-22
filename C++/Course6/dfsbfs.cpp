#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 100000;
vector<int> graph[MAX_N];
bool visitedDfs[MAX_N];
bool visitedBfs[MAX_N];

int n, m;

void dfs(int v) {
	visitedDfs[v] = true;
	cout << v << ' ';

	for (int i = 0; i < graph[v].size(); i++) {
		int k = graph[v][i];
		if (!visitedDfs[k]) {
			dfs(k);
		}
	}
}

void bfs(int root) {
	queue<int> q;

	q.push(root);
	visitedBfs[root] = true;

	while (!q.empty()) {
		int f = q.front();
		q.pop();
		cout << f << ' ';

		for (int i = 0; i < graph[f].size(); i++) {
			int k = graph[f][i];
			if (!visitedBfs[k]) {
				q.push(k);
				visitedBfs[k] = true;
			}
		}

	}

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(0);
	cout << endl;
	bfs(0);
}
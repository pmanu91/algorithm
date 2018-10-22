 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100;

vector<int> graph[MAX];
bool visited[MAX] = { false };
int n, m;

int bfs(int start) {
	queue<int> q;
	int infectedCom = 0;
	
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int f = q.front();
		q.pop();

		for (int i = 0; i < graph[f].size(); i++) {
			int k = graph[f][i];
			if (!visited[k]) {
				visited[k] = true;
				q.push(k);
				infectedCom++;
			}
		}
	}

	return infectedCom;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << bfs(1) << endl;
}
 
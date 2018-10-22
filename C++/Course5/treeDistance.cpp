#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000;

vector<int> tree[MAX];
bool visit[MAX];
int n, x, y;

void dfs(int node, int distance) {
	visit[node] = true;

	if (node == y) {
		cout << distance << endl;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		int k = tree[node].at(i);
		if (!visit[k]) {
			dfs(k, distance + 1);
		}
	}
}

int main() {
	cin >> n >> x >> y;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(x, 0);

}
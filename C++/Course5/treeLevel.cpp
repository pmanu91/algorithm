#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
vector<int> tree[MAX];
bool visit[MAX] = { false };
int maxLevel = 0;
int n, r;

void dfs(int x, int level) {
	visit[x] = true;
	if (maxLevel < level) {
		maxLevel = level;
	}

	for (int i = 0; i < tree[x].size(); i++) {
		int node = tree[x].at(i);
		if (!visit[node]) {
			dfs(node, level + 1);
		}
	}
}

int main() {
	cin >> n >> r;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(r, 0);
	cout << maxLevel << endl;
}
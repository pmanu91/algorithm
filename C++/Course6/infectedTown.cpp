 
#include <iostream>

using namespace std;

const int MAX = 100000;
bool visited[MAX + 1];
int n;

void dfs(int v) {
	visited[v] = true;

	// mul 2
	if (v * 2 <= n) if (!visited[v * 2]) {
		dfs(v*2);
	}

	// div 3
	if (v / 3 != 0) if (!visited[v / 3]) {
		dfs(v / 3);
	}
}

int main() {
	int k;
	cin >> n >> k;

	dfs(k);

	int notInfectedTown = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) notInfectedTown++;
	}
	cout << notInfectedTown << endl;
}
 
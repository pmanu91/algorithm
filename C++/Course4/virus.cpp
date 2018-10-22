#include <iostream>
#include <vector>

using namespace std;

int n;	// computer count
int pc; // pair count
int matrix[101][101];
bool visit[101];

void dfs(int node) {
	visit[node] = true;

	for (int i = 1; i <= n; i++) {
		if (matrix[node][i] == 1 && visit[i] == false) {
			dfs(i);
		}
	}
}

int main() {

	cin >> n >> pc;

	for (int i = 0; i < pc; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		matrix[p1][p2] = matrix[p2][p1] = 1;
	}

	dfs(1);

	int virusComp = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == true) {
			virusComp++;
		}
	}

	cout << virusComp - 1 << endl;
}

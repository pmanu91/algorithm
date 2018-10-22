 
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000;

vector<int> graph[MAX_N];
int paintedColor[MAX_N] = { 0 };
int n, m;
bool result = true;

void dfs(int v, int depth) {
	int color = (depth % 2 == 0) ? 1 : 2;	// select color about depth
	paintedColor[v] = color;
	
	for (int i = 0; i < graph[v].size(); i++) {
		if (!result) return;
		int k = graph[v][i];
		if (paintedColor[k] == 0) {
			dfs(k, depth + 1);
		}
		else {
			int nextColor = ((depth + 1) % 2 == 0) ? 1 : 2;
			if (paintedColor[k] != nextColor) {
				cout << "NO" << endl;
				result = false;
				return;
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

	dfs(0, 0);
	if (result)	cout << "YES" << endl;
}
 
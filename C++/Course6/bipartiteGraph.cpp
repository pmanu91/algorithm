#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000;

vector<int> graph[MAX+1];
int paintedColor[MAX+1] = { 0 };
int n, m;

int result = true;

void bfs(int start) {
	queue<pair<int,int> > q;
	
	paintedColor[start] = 1;
	q.push({ start, 0 });

	while (!q.empty()) {
		int f = q.front().first;
		int d = q.front().second;
		
		q.pop();

		int nextColor = ((d + 1) % 2 == 0) ? 1 : 2;
		for (int i = 0; i < graph[f].size(); i++) {
			int k = graph[f][i];
			if (paintedColor[k] == 0) {
				paintedColor[k] = nextColor;
				q.push({k, d + 1});
			}
			else {
				if (paintedColor[k] != nextColor) {
					result = false;
					return;
				}
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

	bfs(1);
	if (result)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}
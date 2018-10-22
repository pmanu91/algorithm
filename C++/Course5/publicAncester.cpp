#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000;
int parent[MAX];
bool visit[MAX] = { false };
int n, x, y;

void searchParent(int v) {
	if (v == 0) {
		visit[v] = true;
		return;
	}

	if (visit[v]) {
		// public ancestor
		cout << v;
		return;
	}
	visit[v] = true;

	int p = parent[v];
	searchParent(p);
}

void searchParent2(int v) {
	if (v == 0) {
		visit[v] = true;
		cout << v;
		return;
	}

	if (visit[v]) {
		// public ancestor
		cout << v;
		return;
	}
	visit[v] = true;

	int p = parent[v];
	searchParent2(p);
}

int main() {
	cin >> n >> x >> y;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		parent[b] = a;
	}
	
	searchParent(x);
	searchParent2(y);
}

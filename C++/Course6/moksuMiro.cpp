 
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

const int MAX = 1000;
int map[MAX][MAX];
int distance_s[MAX][MAX];
int distance_e[MAX][MAX];
pair<int, int> dir[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} }; // n, e, s, w
int n, m;

int bfs(pair<int, int> p1, pair<int, int> p2) {
	bool visited[MAX][MAX] = { false };
	queue<pair<pair<int, int>, int> > q;	// ((x, y) , distance)
	
	q.push({ {p1.first, p1.second}, 0 });
	visited[p1.second][p1.first] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int distance = q.front().second;

		q.pop();

		//printf("(%d, %d) distance : %d\n", x, y, distance);

		// p2 arrive
		if (x == p2.first && y == p2.second) {
			return distance;
		}

		// N
		if (y - 1 >= 0) if (map[y - 1][x] == 0 && !visited[y - 1][x]) {
			q.push({ {x, y - 1}, distance + 1 });
			visited[y - 1][x] = true;
		}
		else if (x == p2.first && y - 1 == p2.second) {
			q.push({ {x, y - 1}, distance + 1 });
			visited[y - 1][x] = true;
		}
		// E
		if (x + 1 < m) if (map[y][x + 1] == 0 && !visited[y][x + 1]) {
			q.push({ {x+1, y}, distance + 1});
			visited[y][x + 1] = true;
		}
		else if (x + 1 == p2.first && y == p2.second) {
			q.push({ {x + 1, y}, distance + 1 });
			visited[y][x + 1] = true;
		}

		// S
		if (y + 1 < n) if (map[y + 1][x] == 0 && !visited[y + 1][x]) {
			q.push({ {x, y + 1}, distance + 1 });
			visited[y + 1][x] = true;
		}
		else if (x == p2.first && y + 1 == p2.second) {
			q.push({ {x, y + 1}, distance + 1 });
			visited[y + 1][x] = true;
		}

		// W
		if (x - 1 >= 0) if (map[y][x - 1] == 0 && !visited[y][x - 1]) {
			q.push({ {x - 1, y}, distance + 1 });
			visited[y][x - 1] = true;
		}
		else if (x - 1 == p2.first && y == p2.second) {
			q.push({ {x - 1, y}, distance + 1 });
			visited[y][x - 1] = true;
		}
	}
	return -1;
}

bool isInside(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n)
		return true;
	else
		return false;
}

void bfs_stoe(int x, int y) {
	queue<pair<int, int> > q;

	q.push({ 0, n - 1 });
	distance_s[n - 1][0] == 0;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int pX = p.first;
		int pY = p.second;

		q.pop();
		//printf("(%d, %d) distance : %d\n", pX, pY, distance_s[pY][pX]);

		for (int i = 0; i < 4; i++) {
			int nextX = pX + dir[i].first;
			int nextY = pY + dir[i].second;

			if (isInside(nextX, nextY) && distance_s[nextY][nextX] == 0 ) {
				if (map[nextY][nextX] == 0) {
					q.push({nextX, nextY});
					distance_s[nextY][nextX] = distance_s[pY][pX] + 1;
				}
				else {
					distance_s[nextY][nextX] = distance_s[pY][pX] + 1;
				}
			}
		}

	}
}

void bfs_etos(int x, int y) {
	queue<pair<int, int> > q;

	q.push({ m-1, 0 });
	distance_e[0][m - 1] == 0;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int pX = p.first;
		int pY = p.second;

		q.pop();
		//printf("(%d, %d) distance : %d\n", pX, pY, distance_e[pY][pX]);

		for (int i = 0; i < 4; i++) {
			int nextX = pX + dir[i].first;
			int nextY = pY + dir[i].second;

			if (isInside(nextX, nextY) && distance_e[nextY][nextX] == 0) {
				if (map[nextY][nextX] == 0) {
					q.push({ nextX, nextY });
					distance_e[nextY][nextX] = distance_e[pY][pX] + 1;
				}
				else {
					distance_e[nextY][nextX] = distance_e[pY][pX] + 1;
				}
			}
		}

	}
}



int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	bfs_stoe(0, n-1);
	bfs_etos(m - 1, 0);

	int min = 99999;
	if (distance_s[0][m - 1] != 0)
		min = distance_s[0][m - 1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (distance_s[i][j] != 0 && distance_e[i][j] != 0) {
				int distance = distance_s[i][j] + distance_e[i][j];
				if (min > distance) min = distance;
			}
		}
	}

	cout << min << endl;







}

 
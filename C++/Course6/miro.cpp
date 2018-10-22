 


#include <iostream>
#include <vector>
#include <queue>

enum Direction { N, E, S, W };

using namespace std;

const int MAX = 1000;
int map[MAX][MAX];
int n, m;

void bfs(int startX, int startY, bool visited[MAX][MAX] ) {
	queue<pair<int, int> > positionQ;
	queue<int> distanceQ;
	
	positionQ.push({startX, startY});
	distanceQ.push(0);
	visited[startY][startX] = true;

	while (!positionQ.empty() && !distanceQ.empty()) {

		pair<int, int> position = positionQ.front();
		int pX = position.first;
		int pY = position.second;
		int distance = distanceQ.front();

		//cout << "�̵� : (" << pX << ", " << pY << ") | �Ÿ� : " << distance << endl;
		
		// pop in queues
		positionQ.pop();
		distanceQ.pop();

		// arrive end point
		if (pX == m - 1 && pY == 0) {
			cout << distance << endl;
			return;
		}

		// N Check
		if (pY - 1 >= 0) if (map[pY - 1][pX] != 1 && !visited[pY - 1][pX]) {
			positionQ.push({pX, pY - 1});
			distanceQ.push(distance + 1);
			visited[pY - 1][pX] = true;
		}
		// E Check
		if (pX + 1 < m) if (map[pY][pX + 1] != 1 && !visited[pY][pX + 1]) {
			positionQ.push({ pX + 1, pY });
			distanceQ.push(distance + 1);
			visited[pY][pX + 1] = true;
		}
		// S Check
		if (pY + 1 < n) if (map[pY + 1][pX] != 1 && !visited[pY + 1][pX]) {
			positionQ.push({ pX, pY + 1 });
			distanceQ.push(distance + 1);
			visited[pY + 1][pX] = true;
		}
		// W Check
		if (pX - 1 >= 0) if (map[pY][pX - 1] != 1 && !visited[pY][pX - 1]) {
			positionQ.push({pX - 1, pY});
			distanceQ.push(distance + 1);
			visited[pY][pX - 1] = true;
		}
	}

}

int main() {
	bool visited[MAX][MAX] = { false };

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	bfs(0, n-1, visited);
}
 

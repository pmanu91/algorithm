#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 4;
const int MAX_W = 20;
const int MAX_H = 20;
const pair<int, int> dirCal[4] = { {-1, 0}, {0, 1}, {1,0}, {0, -1} }; // N E S W (row, col)
int minBrick = 99999;
vector<vector<int> > minBrickMap;

// 남은 벽돌 갯수 반환
int getBrickCount(vector<vector<int> > map , int w, int h) {
	int count = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] != 0)
				count++;
		}
	}

	return count;
}

//vector< vector<int> > updated_graph;
//updated_graph = bomb(updated_graph)

//vector<int> row(n, 0);
//vector< vector<int> > graph(n, row);

// 아래로 정렬된 벽돌맵을 반환
vector<vector<int> > arrangeBrick(vector<vector<int> > map, int w, int h) {
	vector<vector<int> > newMap(h, vector<int>(w, 0));	// int map[h][w]와 같음
	vector<int> currentFloor(w, h-1);	// 맨 아래부터 벽돌을 쌓을거니까
	
	for (int i = h-1; i >= 0; i--) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] != 0) {
				newMap[currentFloor[j]][j] = map[i][j];
				currentFloor[j]--;	// 쌓고나면 다음층으로
			}
		}
	}
	return newMap;
}

// 해당 행과 열을 폭파시킨다 모두 폭파된 상태의 그래프를 반환
vector<vector<int> > bomb(vector<vector<int> > map, int r, int c) {
	queue<pair<int, int> > q;
	bool visited[MAX_H][MAX_W] = {};

	q.push({r, c});
	visited[r][c] = true;

	while (!q.empty()) {
		pair<int, int> f = q.front();
		int range = map[f.first][f.second];
		map[f.first][f.second] = 0;
		q.pop();
		
		// 세로 폭발
		for (int i = 1; i < range; i++) {
			if (f.first - i >= 0 && !visited[f.first - i][f.second]) {
				q.push({ f.first - i, f.second });
				visited[f.first - i][f.second] = true;
			}
			if (f.first + i < map.size() && !visited[f.first + i][f.second]) {
				q.push({ f.first + i, f.second });
				visited[f.first + i][f.second] = true;
			}
		}

		// 가로 폭발
		for (int i = 1; i < range; i++) {
			if (f.second - i >= 0 && !visited[f.first][f.second - i]) {
				q.push({ f.first, f.second - i });
				visited[f.first][f.second - i] = true;
			}
			if (f.second + i < map[0].size() && !visited[f.first][f.second + i]) {
				q.push({ f.first, f.second + i });
				visited[f.first][f.second + i] = true;
			}
		}
	}

	return map;
}

// 해당 열에 구슬을 떨어트려 폭파된 그래프를 반환
vector<vector<int> > attack(vector<vector<int> > map, int col, int w, int h) {
	vector<vector<int> > updated_graph = map;
	bool isEmpty = true;
	for (int r = 0; r < h; r++) {
		if (map[r][col] != 0) {
			updated_graph = arrangeBrick(bomb(map, r, col), w, h);
			isEmpty = false;
			break;
		}
	}
	return updated_graph;
}

void printMap(vector<vector<int> > map, int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}


void dfs(vector<vector<int> > map, int n, int w, int h) {
	if (minBrick == 0) return; // 이미 0인경우를 구한경우 더이상 탐색할필요없음
	if (n == 0) {
		// 남은 벽돌갯수 비교 후 교체
		int brickCount = getBrickCount(map, w, h);
		
		if (minBrick > brickCount) {
			minBrick = brickCount;
			minBrickMap = map;
		}
		return;
	}
	for (int i = 0; i < w; i++) {
		vector<vector<int> > updated_map = attack(map, i, w, h);
		dfs(updated_map, n - 1, w, h);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		minBrick = 99999;
		/////////////////////////////////////////////////////////////////////////////////////////////

		int N, W, H;

		cin >> N >> W >> H;

		vector<vector<int> > map(H, vector<int>(W,0));
		int temp;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> temp;
				map[i][j] = temp;
			}
		}
		
		dfs(map, N, W, H);

		cout << "#" << test_case << " " << minBrick << endl;
		//printMap(minBrickMap, W, H);

		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
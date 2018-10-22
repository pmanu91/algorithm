#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

const int MAX = 1000;
const pair<int, int> dirCal[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // N E S W

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		int n, m, k;

		cin >> n >> m >> k;

		queue<pair<int, int> > na_q;
		queue<pair<int, int> > a_q;

		char grid[MAX][MAX] = {};
		char cell_grid[MAX][MAX] = {};
		int left = MAX / 2;
		int top = MAX / 2;

		for (int i = top; i < top + n; i++) {
			for (int j = left; j < left + m; j++) {
				int temp;
				cin >> temp;
				grid[i][j] = temp;
				cell_grid[i][j] = temp;
				if (temp != 0)
					na_q.push({ i, j });	// 초기상태 비활성세포 큐에 추가
			}
		}
		
		int time = 0;
		while (time <= k) {
			// cout << "활성세포수 : " << a_q.size() << endl;
			// cout << "비활성세포수 : " << na_q.size() << endl;

			// 활성 큐에 있는 세포 번식
			bool visited[MAX][MAX] = {};
			queue<pair<int, int> > temp_q;	// 새로 번식된 세포가 잠시 보관될 큐

			while (!a_q.empty()) {
				pair<int, int> na_cell = a_q.front();
				int cr = na_cell.first;
				int cc = na_cell.second;
				a_q.pop();

				for (int i = 0; i < 4; i++) {
					int nextCell = grid[cr + dirCal[i].first][cc + dirCal[i].second];
					if (nextCell == 0) {	// 다음에 번식할 위치의 셀이 비어있으면
						grid[cr + dirCal[i].first][cc + dirCal[i].second] = cell_grid[cr][cc];	// 같은 생명력의 셀로 번식
						cell_grid[cr + dirCal[i].first][cc + dirCal[i].second] = cell_grid[cr][cc];	// 같은 생명력의 셀로 번식
						visited[cr + dirCal[i].first][cc + dirCal[i].second] = true;
						temp_q.push({ cr + dirCal[i].first, cc + dirCal[i].second });	// 새로 번식한 세포를 임시큐에 저장
						// cout << "번식 ";
					}
					else if (nextCell != 0 && visited[cr + dirCal[i].first][cc + dirCal[i].second]) {
						// 셀이 비어있지 않은데 지금 막 생긴 세포라면
						// 더 큰 생명력의 세포로 변경
						if (cell_grid[cr + dirCal[i].first][cc + dirCal[i].second] < cell_grid[cr][cc]) {
							grid[cr + dirCal[i].first][cc + dirCal[i].second] = cell_grid[cr][cc];
							cell_grid[cr + dirCal[i].first][cc + dirCal[i].second] = cell_grid[cr][cc];
						}
					}
				}

				// 번식을 완료한 셀은 죽음
				grid[cr][cc] = -1;
			}
			// cout << endl;

			// 비활성세포 큐에 있는 세포들 중 남은 생명력이 1이면 활성세포 큐로 옮김
			while (!na_q.empty()) {
				pair<int, int> cell = na_q.front();
				int cr = cell.first;
				int cc = cell.second;
				na_q.pop();
				//printf("%d ", grid[cr][cc]);
				if (grid[cr][cc] == 1) {
					a_q.push(cell);

				}
				else if (grid[cr][cc] > 1) {	// 나머지 비활성 세포는 생명력 1감소
					grid[cr][cc]--;
					temp_q.push(cell);	// 임시큐에 잠시 저장
				}
			}
			// cout << endl;
			
			// 새로 번식된 세포를 비활성 세포 큐로 옮김
			while (!temp_q.empty()) {
				na_q.push(temp_q.front());
				temp_q.pop();
			}

			time++;
			// cout << "time : " << time << endl;
		}
		/*
		for (int i = top - k; i < top + n + k; i++) {
			for (int j = left - k; j < left + m + k; j++) {
				printf("%3d", cell_grid[i][j]);
			}
			cout << endl;
		}
		for (int i = top - k; i < top + n + k; i++) {
			for (int j = left - k; j < left + m + k; j++) {
				printf("%3d", grid[i][j]);
			}
			cout << endl;
		}
		*/
		
		cout << "#" << test_case << " " << a_q.size() + na_q.size() << endl;
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
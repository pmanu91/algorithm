#include <iostream>
#include <list>
#include <vector>

using namespace std;

enum Direction { N, E, S, W };

const int MAX_N = 100;
const int MAX_K = 100;
pair<int, int> dirCal[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // (row, col)
int n, k, l;
int map[MAX_N + 1][MAX_N + 1] = {0,};
list<pair<int, int> > snake;
vector<pair<int, int> > command;	// time(sec), Direction

int direction = E; // first direction E
int sec = 0;
bool gameover = false;

void changeDirection(char nextDirection) {
	if (nextDirection == 'L') {
		direction = (direction + 3) % 4;
	}
	else { // 'D'
		direction = (direction + 1) % 4;
	}
	//cout << direction << "으로 방향전환 sec : " << sec << endl;
}

bool checkPath(int r, int c) {
	if (r < 1 || r > n || c < 1 || c > n) {	// 경로 밖
		//cout << "벽에 부딪힘" << endl;
		return false;
	}
	else {
		if (map[r][c] == 1) {	// 자신의 몸
			//cout << "몸체에 부딪힘" << endl;
			return false;
		}
	}
	return true;
}

void moveStart() {
	int cmd = 0;
	bool flag = 0; // 커맨드 수행이 모두 끝나면 1이 됨
	snake.push_back({ 1, 1 });
	map[1][1] = 1;

	while (1) {

		//cout << "time: " << time << endl;
		if (!flag && sec == command[cmd].first) {
			changeDirection(command[cmd++].second);
			if (cmd == command.size()) flag = 1; // 커맨드를 전부 수행한 경우 플래그를 1로 변환
		}

		pair<int, int> head = snake.front();

		int nextRow = head.first + dirCal[direction].first;
		int nextCol = head.second + dirCal[direction].second;

		// 벽이나 뱀의 몸체에 닿으면 게임오버
		if (!checkPath(nextRow, nextCol)) {
			gameover = true;
			return;
		}
			
		// 다음경로에 사과가 있지 않다면 꼬리를 삭제
		if (map[nextRow][nextCol] != 2) {
			pair<int, int> tail = snake.back();
			map[tail.first][tail.second] = 0;
			snake.pop_back();
		}

		// 머리를 다음경로에 추가
		snake.push_front({nextRow, nextCol});
		map[nextRow][nextCol] = 1;

		sec++;
		//cout << "sec : " << sec << endl;
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int ar, ac;
		cin >> ar >> ac;
		map[ar][ac] = 2;
	}
	
	cin >> l;
	for (int i = 0; i < l; i++) {
		int time;
		char nextDirection;
		cin >> time >> nextDirection;
		command.push_back({time, nextDirection});
	}
	
	moveStart();

	cout << sec + 1 << endl;

	return 0;
}
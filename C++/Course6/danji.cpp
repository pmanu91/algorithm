#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 25;
char map[MAX][MAX];
int danji[1000];
int danjiCount = 0;
int n;

int checkDanji(int x, int y, char name) {
	queue<pair<int, int> > q;
	int houseCount = 0;

	// change house by danjiName, houseCount + 1 and push position into queue
	q.push({x, y});
	map[y][x] = name;
	houseCount++;

	while (!q.empty()) {
		pair<int, int> position = q.front();
		int pX = position.first;
		int pY = position.second;
		q.pop();
		
		// N
		if (pY - 1 >= 0) if (map[pY - 1][pX] == '1') {
			q.push({pX, pY - 1});
			map[pY - 1][pX] = name;
			houseCount++;
		}
		// E
		if (pX + 1 < n) if (map[pY][pX + 1] == '1') {
			q.push({pX + 1, pY});
			map[pY][pX + 1] = name;
			houseCount++;
		}

		// S
		if (pY + 1 < n) if (map[pY + 1][pX] == '1') {
			q.push({pX, pY + 1});
			map[pY + 1][pX] = name;
			houseCount++;
		}

		// W
		if (pX - 1 >= 0) if (map[pY][pX - 1] == '1') {
			q.push({pX - 1, pY});
			map[pY][pX - 1] = name;
			houseCount++;
		}
	}

	return houseCount;
}

void searchHouse() {
	char danjiName = 'A';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1') {
				// check danji
				int houseCount = checkDanji(j, i, danjiName++);
				danji[danjiCount++] = houseCount;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	searchHouse();

	sort(danji, danji+danjiCount);
	
	// print result
	cout << danjiCount << endl;
	for (int i = 0; i < danjiCount; i++) {
		cout << danji[i] << endl;
	}
}
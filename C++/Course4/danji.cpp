#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


int danjiCount = 0;
void printDanjiCount(int danji[1000]) {
	sort(danji, danji + danjiCount);
	cout << danjiCount << endl;
	for (int i = 0; i < danjiCount; i++) {
		cout << danji[i] << endl;
	}
}

void printDanjiMap(int n, char map[30][30]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

void checkDanji(int n, char map[30][30], int danji[1000], int danjiIdx, char danjiName, int x, int y) {
	if (x >= n || x < 0 || y >= n || y < 0) return; // out of boundary
	if (map[y][x] != '1') return; // not house

	map[y][x] = danjiName;	// set danji
	danji[danjiIdx]++;	// danji house count + 1

	// north
	checkDanji(n, map, danji, danjiIdx, danjiName, x, y - 1);
	// east
	checkDanji(n, map, danji, danjiIdx, danjiName, x + 1, y);
	// south
	checkDanji(n, map, danji, danjiIdx, danjiName, x, y + 1);
	// west
	checkDanji(n, map, danji, danjiIdx, danjiName, x - 1, y);
}

void searchHouse(int n, char map[30][30], int danji[1000]) {
	char danjiName = '2'; // start from 2 
	int danjiIdx = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == '1') {
				danjiCount++;
				checkDanji(n, map, danji, danjiIdx++, danjiName++, x, y);
			}
		}
	}

}

int main() {
	int n;
	char map[30][30];
	int danji[1000] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	searchHouse(n, map, danji);
	//printDanjiMap(n, map);
	printDanjiCount(danji);
}

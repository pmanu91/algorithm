#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char bu[10];
int visited[10];
int k;
vector<string> vs;
void dfs(int len, string s) {
	if (len == k + 1) {
		vs.push_back(s);
		return;
	}
	char buu = bu[len];
	int lastnum = s[s.length() - 1] - '0';
	for (int i = 0; i <= 9; ++i) {
		if (visited[i] == 1)continue;
		if (buu == '<') {
			if (lastnum < i) {
				visited[i] = 1;
				char ss = i + '0';
				string ns = s + ss;
				dfs(len + 1, ns);
				visited[i] = 0;
			}
		}
		else {
			if (lastnum > i) {
				visited[i] = 1;
				char ss = i + '0';
				string ns = s + ss;
				dfs(len + 1, ns);
				visited[i] = 0;
			}
		}
	}

}

int main() {
	cin >> k;
	for (int i = 1; i <= k; ++i)cin >> bu[i];
	for (int i = 0; i <= 9; ++i) {
		visited[i] = 1;
		char ss = i + '0';
		string ins = ""; ins += ss;
		dfs(1, ins);
		visited[i] = 0;
	}
	sort(vs.begin(), vs.end());
	cout << vs[vs.size() - 1] << endl << vs[0] << endl;
	return 0;
}

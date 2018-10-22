// 어떤 수열이 주어질 때 등차수열로 만들려면
// 최소 몇개의 원소를 다른 수로 바꿔야 하는지 알아내라

// 1 3 0 7 9 --> 공차가 2일 때 0을 5로 만들면 등차수열이 됨 return 1
// 1 3 2 4 5 --> 공차가 1일 때 3을 2로 만들고 2를 3으로 만들면 등차수열이 됨 return 2
// 1 10 2 12 3 14 4 16 5  --> 1 2 3 4 5 를 남기면 등차수열을 만들 수 없음 return 5

#include <iostream>
#include <vector>

using namespace std;

// 2개의 임의의 수를 뽑아서 그 두 수가 등차수열의 일부라고 가정하고
// 공차를 구한다.
// 하나의 피봇원소를 기준으로 좌측과 우측의 해당하는 공차에 맞지 않는 수의 갯수를 구하고
// 그 갯수의 최솟값을 구한다
// 시간복잡도
// 두 개의 원소를 고르는 것 O(n^2)
// 좌측과 우측의 등차수열원소 판단 O(n)
// O(n^3)
int solution(vector<int> A) {
	int result = 0;

	int min = 9999999;
	for (int i = 0; i < A.size(); i++) {	// i가 기준(피봇원소)
		for (int j = i + 1; j < A.size(); j++) {	// 피봇원소와 등차수열의 일부가 될 원소
			int gongcha = (A[j] - A[i]) / (j - i);	// 공차는 (두 원소의 차이 / 수열의 거리 차이) 
			int count = 0;

			// left
			for (int k = i - 1; k >= 0; k--) {
				if (A[k] != A[i] - gongcha * (i - k))
					count++;
			}
			// right
			for (int k = i + 1; k < A.size(); k++) {
				if (A[k] != A[i] + gongcha * (k - i))
					count++;
			}

			if (count < min) min = count;
		}
	}
	result = min;
	return result;
}

int main() {
	vector<int> A = { 1, 3, 0, 7, 9 };
	cout << solution(A) << endl;

}
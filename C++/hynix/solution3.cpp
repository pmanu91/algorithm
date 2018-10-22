// 피보나치수열은 1 1 2 3 5 8
// f(n) + f(n+1) = f(n+2) 이다
// f(0) = 'A' f(1) = 'B' f(2) = 'AB' f(3) = 'BAB' f(4) = 'ABBAB' 일 때 
// 1. f(n)을 char *result 에 저장하라
// 2. n과 k가 주어질 때 f(n)의 k번째 문자를 구하라.

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// 3-1 번의 경우 재귀를 이용한 방법과 memoization을 이용한 방법이 있다.
// 재귀를 이용한 방법은 직관적이고 쉽다. 하지만 한번 호출했던 부분을 
// 여러번 호출하기 때문에 시간적 그리고 스택의 공간적인 낭비가 다소 있다.
// 재귀로 호출했을 때는 한 함수당 2개의 함수를 호출하기 때문에 
// 대략 O(2^n)의 시간복잡도를 나타냄
// 메모이제이션을 이용하여 풀면 이미 구한 함수에 대해서 저장하고 있기 때문에
// O(n)의 시간복잡도를 가지고 있다.


// 3-2 번의 다른 풀이법
// 3-1번의 함수를 이용해서 문자열을 구한 후 해당 문자를 가져오는 식으로 할경우
// n이 커질경우 메모리에 상당한 부하가 오기 때문에 좋은 해결법은 아닌것 같다.
// 그래서 다른 풀이법으로는 기존의 피보나치수열을 이용하는 것인데
// f(n) 피보나치문자열의 k번째 문자를 구하기 위해서
// f(n)의 문자열의 크기 = f(n-2)의 문자열의 크기 + f(n-1)의 문자열의 크기 를 이용할 수있다.
// 이것은 곳 기존 피보나치 수열과 동일 하다.
// f(n)에서 k의 값이 f(n-2)보다 크다면 f(n-1)에서 k - f(n-2)번째 문자열을 찾으면 되고
// k의 값이 f(n-2)보다 작거나 같다면 f(n-2)에서 k번째 문자열을 찾으면 된다.
// 하향식으로 내려가다가 f(0)에서 1번째 문자를 찾거나 f(1)에서 첫번째 문자를 찾으면
// f(0)의 1번째 문자는 'A' 를 반환하고 f(1)의 1번째 문자면 'B'를 반환하면 된다.

// 메모이제이션 loop dp
void fibo(uint64_t n, char* result) {
	vector<string> str;
	str.resize(n+1);
	str[0] = "A";
	str[1] = "B";
	for (int i = 2; i <= n; i++) {
		str[i] = str[i - 2] + str[i - 1];
	}
	for (int i = 0; i < str[n].size(); i++) {
		result[i] = str[n][i];
	}
	result[str[n].size()] = '\0';
}

// 일반 재귀 피보나치
string fibo2(uint64_t n) {
	if (n == 0) return "A";
	if (n == 1) return "B";
	return fibo2(n - 2) + fibo2(n - 1);
}

// 메모이제이션 재귀 피보나치
string memo[50];
string fibo3(uint64_t n, char *result) {





	return "";
}

char solve(uint64_t n, uint64_t k) {
	vector<uint64_t> f;
	f.resize(n+1);
	f[0] = f[1] = 1;

	for (uint64_t i = 2; i <= n; i++) {
		f[i] = f[i - 2] + f[i - 1];
	}
	char* result = new char[f[n] + 1];
	fibo(n, result);
	return result[k];
}

char solve2(uint64_t n, uint64_t k) {
	string str = fibo2(n);
	return str[k-1];
}

char solve3(uint64_t n, uint64_t k) {
	uint64_t f[100];
	f[0] = 1;
	f[1] = 1;
	for (uint64_t i = 2; i <= n; i++) {
		f[i] = f[i - 2] + f[i - 1];
	}
	
	// 여기서 k의 값을 찾아나가는 과정
	// k가 f(n-2)보다 작거나 같다면 f(n-2)의 k번째 문자와 같고
	// k가 f(n-2)보다 크다면 f(n-1)의 k-f(n-2) 번째 문자와 같다.
	// 하향식으로 내려가서 f(0)의 첫번째 문자열이나 f(1)의 첫번째 문자열을 찾게 되면
	// k번째 문자가 'A'인지 'B'인지 알수 있다.

	while (1) {
		if (n == 0 && k == 1) {
			return 'A';
		}
		else if (n == 1 && k == 1) {
			return 'B';
		}

		if (k <= f[n - 2]) {
			n = n - 2;
		}
		else if (k > f[n - 2]) {
			k = k - f[n - 2];
			n = n - 1;
		}
	}
}

int main() {
	char* result = new char[100000];

	//fibo(10, result);
	//cout << result << endl;
	//cout << fibo2(5) << endl;
	cout << solve3(50, 122) << endl;
}
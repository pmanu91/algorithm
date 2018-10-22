#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

int hexToDecimal(char *hex) {
	int decimal = strtoul(hex, NULL, 16);
	//cout << hex << " : " << decimal << endl;
	return decimal;
}

unsigned int hexStrToDecimal(string hexString) {
	unsigned int x;
	stringstream ss;
	ss << hex << hexString;
	ss >> x;
	return x;
}

// k번째 수 가져오기(중복된 경우 고려하여)
int getNumber(vector<int> numV, int k) {
	if (k == 1) return numV[0];
	int prev = numV[0];
	int c = 1;
	for (int i = 1; i < numV.size(); i++) {
		if (numV[i] != prev) c++;
		if (c == k) return numV[i];
		prev = numV[i];
	}
}


int main() {

	int T; // test case
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		int N, K;
		cin >> N >> K;

		char n[30];
		cin >> n;

		// 테스트케이스 로직 시작

		int numEdge = N / 4;	// 한변의 숫자 갯수
		vector<int> numV;	// 정렬된 숫자가 들어갈 배열
	
		for (int i = 0; i < numEdge; i++) {	// numEdge만큼 회전하면 다시 돌아옴
			for (int j = i; j <= N - numEdge + (i+1); j+=numEdge) {
				
				//char *hexNumber = new char[numEdge + 2];
				//hexNumber[0] = '0'; hexNumber[1] = 'x';
				//for (int k = 2; k < numEdge+2; k++) {	// numEdge개씩 문자열을 추출
				//	hexNumber[k] = n[(j + k) % N];
				//}
				//hexNumber[numEdge + 2] = NULL;	// 문자열의 끝

				//int decimal = hexToDecimal(hexNumber);	// 16진수 문자열을 10진수로 변환
				

				string hexString = "";
				for (int k = 0; k < numEdge; k++) {	// numEdge개씩 문자열을 추출
					hexString += n[(j + k) % N];
				}
				int decimal = hexStrToDecimal(hexString);

				numV.push_back(decimal);	// 배열에 추가
			}
		}

		// 벡터 정렬 (내림차순)
		sort(numV.begin(), numV.end(), greater<int>());

		cout << "#" << t << " " << getNumber(numV, K) << endl;

		// 테스트케이스 로직 종료
	}
}
#include<iostream>
#include<string>
using namespace std;
string S, P;
int pi[1000001] = { 0, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> S >> P;
	int n = S.length(); int m = P.length();
	for (int i = 1, j = 0; i < m; i++) {
		while (j && P[i] != P[j]) {
			j = pi[j - 1];//현재 j이전까지 같은 부분이었던 idx로 이동
		}
		if (P[i] == P[j]) {
			pi[i] = ++j;
		}
	}
	bool flag = false;
	for (int i = 0, j = 0; i < n; i++) {
		while (j && S[i] != P[j]) {
			j = pi[j - 1];
		}
		if (S[i] == P[j]) {
			if (j == m - 1) {
				flag = true;
				break;
			}
			else ++j;
		}
	}
	if (flag) {
		cout << 1;
	}
	else cout << 0;
}

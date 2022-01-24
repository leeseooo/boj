#include <iostream>
#include<algorithm>
using namespace std;
int n, k;
int dp[1001][1001] = { 0, };
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j || j == 0) { //왼쪽가생이 오른쪽가생이는 다 1
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007; //피보나치
		}
	}
	cout << dp[n][k];
	return 0;
}

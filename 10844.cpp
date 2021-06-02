#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
long long dp[101][11];
#define DIV 1000000000
int main() {
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	dp[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)dp[i][j] = dp[i - 1][j + 1] % DIV;
			else if (j == 9)dp[i][j] = dp[i - 1][j - 1] % DIV;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % DIV;
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
	}
	cout << ans % DIV;
}

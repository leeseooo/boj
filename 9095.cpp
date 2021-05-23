#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
#include<memory.h>
#include<stack>
#include<cstdlib>
#include<climits>
using namespace std;
int main() {
	int n, t;
	cin >> t;
	int dp[11];
	dp[1] = 1, dp[2] = 2, dp[3] = 4; //각 case의 결과값
	while (t--) {
		cin >> n;
		if (n <= 3) {
			cout << dp[n] << "\n";
			continue;
		}
		else {
			for (int i = 4; i <= n; i++) {
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
			}
		}
		cout << dp[n] << "\n";
	}
}

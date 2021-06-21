#include<iostream>
#include<algorithm>
using namespace std;
long long dp[101];
int n;
int main() {
	int t;
	cin >> t;

	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[1] + dp[3]; dp[5] = dp[4];

	while (t--) {
		cin >> n;
		for (int i = 6; i <= n; i++) {
			dp[i] = dp[i - 5] + dp[i - 1];
		}
		cout << dp[n] << "\n";
	}
}

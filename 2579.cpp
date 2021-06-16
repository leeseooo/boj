#include<iostream>
#include<algorithm>
using namespace std;
int arr[300];
int dp[2][300];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[0][0] = 0;
	dp[0][1] = dp[1][1] = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[0][i] = max(dp[0][i - 2] + arr[i], dp[1][i - 2] + arr[i]);
		dp[1][i] = max(dp[1][i], dp[0][i - 1] + arr[i]);
	}
	int ans = max(dp[0][n], dp[1][n]);
	cout << ans;
}

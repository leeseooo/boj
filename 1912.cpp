#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[100001];
int dp[100001];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	int ans = dp[1]; //초기값 0으로 주면 음수 case에서 틀림 주의
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
}

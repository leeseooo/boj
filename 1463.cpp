#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int dp[1000001]; //정수 n을 1로 만드는 데 필요한 최소 연산 횟수
int main() {
	int n;
	cin >> n;

	//n은 n-1에서 1을 더하고
	//n/2에서 2를 곱하고
	// n/3에서 3을 곱해서 만들 수 있다.
	//dp[n] = min(dp[n-1]+1, dp[n/2]+1, dp[n/3]+1)

	//bottom up
	for (int i = 2; i <= n; i++) {//1이면 연산 안해도 되므로 2부터 시작시킴
		dp[i] = dp[i - 1] + 1; //dp에 이전 연산횟수 + 1
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0) { 
			dp[i] = min(dp[i], dp[i / 3] + 1); 
		}
	}
	cout << dp[n];

}
//주어진 수(N)을 1로 만드는 최소 횟수는 =  'N-1을 1로 만드는 최소 횟수 + 1번' 또는 'N/2를 1로 만드는 최소 횟수 +1번' 또는 'N/3을 1로 만드는 최소 횟수 + 1번'

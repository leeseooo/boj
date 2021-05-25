#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int arr[1001];
int dp[1001];
int sum = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i],dp[j]+arr[i]); 
				//이전값dp[j]에 현재arr[i] 합한값과 비교
				//틀린 점화식 : dp[i]+dp[j]로 하면 dp의 값이 변함
			}
		}
		sum = max(sum, dp[i]);
	}
	cout << sum;
}

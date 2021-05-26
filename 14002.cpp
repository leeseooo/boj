#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int arr[1001];
int dp[1001];
vector<int>v[1001];
vector<int>ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		v[i].push_back(arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j]+1) {
					v[i].clear();
					v[i] = v[j]; //이전벡터 복붙
					v[i].push_back(arr[i]); //그 뒤에 더큰값 푸시
					dp[i] = dp[j] + 1; //수열길이 증가
				}
			}
		}
		if (ans.size() < v[i].size()) {// 더 긴 수열일때 갱신
			ans = v[i];
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}

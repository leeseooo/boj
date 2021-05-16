#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int n, m;
int ans = 0;
int arr[1000001];
void dfs(int time, int idx, int snow) {
	ans = max(ans, snow);
	if (time == 0 || idx > n) return;//시간이 0이 되거나 index가 크기 넘어가는 경우 처리
  //☆★☆★
	dfs(time - 1, idx + 1, snow + arr[idx + 1]);
	dfs(time - 1, idx + 2, snow / 2 + arr[idx + 2]);
	//눈덩이 조건에 맞게 dfs 두번 해주고 ans에 더 큰값 저장하는 방법으로 풀이 가능
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dfs(m, 0, 1);
	cout << ans;
}

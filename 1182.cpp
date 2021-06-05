#include<iostream>
#include<algorithm>
using namespace std;
int arr[20];
int n, s;
int ans = 0;
void dfs(int sum, int idx) {
	if (idx == n) return; //범위 초과 시 종료
	if (sum + arr[idx] == s) ans++;

	dfs(sum, idx + 1); //현재 배열값 더하지 않는 경우
	dfs(sum + arr[idx], idx + 1); //현재 배열값 더하는 경우
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);
	cout << ans;
}

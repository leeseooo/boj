#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
#include<memory.h>
using namespace std;
int t, n;
int cnt = 0;
int arr[1001];
bool visit[1001];
void dfs(int node) {
	visit[node] = true;
	int next = arr[node];
	if (!visit[next]) {
		dfs(next);
	}
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				dfs(i);
				cnt++;//사이클 끝나고 돌아오면 카운트 증가
			}
		}
		cout << cnt << "\n";
		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		cnt = 0;
	}
}

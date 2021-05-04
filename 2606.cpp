#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
int n, m;
int com[101][101];
bool visit[101];
int cnt = 0;
void dfs(int x) {
	visit[x] = true;
	for (int i = 1; i <= n; i++) {
		if (com[x][i] == 1 && visit[i] == false) {
			dfs(i);
			cnt++;
		}
	}
}
int main() {
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		com[a][b] = 1;
		com[b][a] = 1;
	}
	dfs(1);
	cout << cnt;
}

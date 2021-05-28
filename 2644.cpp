#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>
using namespace std;
int n, p1, p2, m, x, y;
vector<int>v[101];
bool visit[101];
bool flag = false;
void dfs(int node, int cnt) {
	visit[node] = true;
	if (node == p2) {
		cout << cnt;
		flag = true;
		return;
	}
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!visit[next]) { //사촌관계가 있고, 방문하지 않은것에 대해 탐색
			dfs(next, cnt + 1);
		}

	}
}
int main() {
	cin >> n >> p1 >> p2 >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(p1, 0);
	if(!flag)
		cout << "-1";
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int n, m, u, v;
vector<int>vec[1001];
bool visited[1001];
bool finish[1001];
int cnt=0;
void dfs(int node) {
	visited[node] = true;
	for (int i = 0; i < vec[node].size(); i++) {//방향성이 없는 그래프이므로 반복문 돌려주면서 연결요소 탐색
		int next = vec[node][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		vec[u].push_back(v);//특정 ved[idx] 안에 딸린 요소 삽입
		vec[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {//정점 1부터 n까지
		if (!visited[i]) {
		  dfs(i);
      cnt++;
		}
	}
	cout << cnt;
}

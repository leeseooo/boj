#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>v[100001];
bool visit[100001];
int ans[100001];
void dfs(int node) {
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!visit[next]) {
			ans[next] = node; //next의 부모를 현재 node로 지정
			dfs(next);
		}
	}
}
int main() {
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		v[a].push_back(b); //양방향 저장
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++ ) {
		cout << ans[i] << "\n";
	}
}

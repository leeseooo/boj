#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<memory.h>
using namespace std;
int n, m;
vector<int>v[10001];
bool visit[10001];
void dfs(int node) {
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}
int check() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i])cnt++;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	vector<pair<int,int>>ans;
	int max_n = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i);
		int res = check();
		max_n = max(max_n, res);
		ans.push_back({ res,i });
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].first == max_n) {
			cout << ans[i].second << ' ';
		}
	}
}

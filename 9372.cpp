#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
int t, n, m, a, b;
int ans = 0;
vector<int>v[1001];
bool visit[1001];
void dfs(int x) {
	visit[x] = true; //방문
	for (int i = 0; i < v[x].size(); i++) { //현 국가에서 갈 수 있는 만큼 반복
		int next = v[x][i];
		if (!visit[next]) {
			ans++;
			dfs(next);
		}
	}
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			v[a].push_back(b); //a와 b를 왕복하므로 양방향으로 해줌
			v[b].push_back(a);
		}
		dfs(1); //1번 국가부터 탐색
		cout << ans << "\n";
		memset(visit, false, sizeof(visit));
		memset(v, 0, sizeof(v));
		ans = 0;
	}
}

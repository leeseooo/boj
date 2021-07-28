#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
int n, m;
int a, b;
vector<int>v[2001];
bool visit[2001];
bool flag = false;
void dfs(int node, int cnt) {
	if (cnt == 5) {//cnt==5는 한 사람에게서 타고 타고 5명까지 친구관계라는 뜻
		//연속해서 4번, depth가 4인것과 같은 의미. 
		flag = true;
		return;
	}
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!visit[next]) {
			dfs(next, cnt + 1);
			if (flag)return;
		}
	}
	//계속 연결되는 간선이 아니고 건너뛰어 연결되는 간선을 먼저 타는 예외가 있을 수 있음
	//dfs 스택을 따라 return을 할 때 방문처리를 삭제해주어야 한다.
	//삭제해주면 이전node로 돌아가서 새로운 간선 탐색할 때 깊이를 갱신할 수 있다.
	visit[node] = false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i, 1);
		if (flag) break;
	}
	if (flag) cout << 1;
	else cout << 0;
}

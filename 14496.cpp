#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<memory.h>
using namespace std;
using pii = pair<int, int>;
int a, b, n, m;
vector<int>v[1001];
int visit[1001];
void bfs() {
	queue<int>q;
	q.push(a);
	visit[a] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == b) {
			cout << visit[x];
			return;
		}
		for (int next : v[x]) {
			if (visit[next] == -1) {
				visit[next] = visit[x] + 1;
				q.push(next);
			}
		}
	}
	cout << -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(visit, -1, sizeof(visit));
	bfs();
}

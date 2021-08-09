#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
#define MAX 1001
#define INF 987654321
int n, m;
int Start, End;
int dist[MAX];
vector<pair<int, int>>vec[MAX];
void solve() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,Start });//비용, 현재정점
	dist[Start] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

    //새로 갱신되는 정점과 비용이 pq에 계속 들어가는데,
    //이미 중간에 더 최소비용으로 갱신되었다면 다시 해당 정점을 만났을 때 건너뛰어서 시간초과를 방지한다.
		if (dist[cur] < cost)continue;

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int nextCost = vec[cur][i].second;
			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				pq.push({ dist[next],next });
			}
		}
	}
	cout << dist[End];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		vec[s].push_back({ e,w });
	}
	cin >> Start >> End;
	for (int i = 1; i <= n; i++)dist[i] = INF;
	solve();
}

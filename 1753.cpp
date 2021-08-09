#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
#define MAX 20001
#define INF 987654321
int V, E, K;
int dist[MAX];//각 정점까지 가는 데 드는 최소비용
vector<pair<int, int>>vec[MAX];
void solve() {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//값이 작을수록 우선순위를 갖도록 한다.
	pq.push({ 0,K });//비용,정점
	dist[K] = 0;
	
	while (!pq.empty()) {
		int cost = pq.top().first;//현재 정점까지의 비용
		int cur = pq.top().second;//현재 정점 위치
		pq.pop();

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first; //현재 정점이 가리키는 다음 정점
			int nextCost = vec[cur][i].second; //가중치

			if (dist[next] > cost + nextCost) {//더 최소인 비용을 저장
				dist[next] = cost + nextCost;
				pq.push({ dist[next],next });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		vec[v].push_back({ u,w });
	}
	for (int i = 1; i <= V; i++)dist[i] = INF;
	solve();
}

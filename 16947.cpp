#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
using namespace std;
int n;
vector<int>v[3001];
bool visit[3001] = { false, };
int prevNode[3001] = { 0, };
bool flag = false;
bool cycle[3001] = { false, };
int dist[3001] = { 0, };
void findCycle(int node) {
	visit[node] = true;

	for (int i = 0; i < v[node].size(); i++) {
		if (flag)return;
		int next = v[node][i];

		if (!visit[next]) {
			prevNode[next] = node; // next의 부모는 node
			findCycle(next);
		}
		// next가 현재 node의 부모가 아니였다면 사이클
		else if(next != prevNode[node]){
			flag = true; // 찾았으니까 재귀 끝내기 위한 변수
			cycle[next] = true;

			while (next != node) {
				cycle[node] = true;
				node = prevNode[node];
			}
			return;
		}
	}
}
// 순환선과 역 사이 거리 재기
void bfs() {
	queue<pair<int, int>>q; // 현재 노드, 거리
	for (int i = 1; i <= n; i++) {
		if (cycle[i]) {
			q.push({ i,0 }); // 순환선에 속한 노드 저장
			visit[i] = true; // 순환선 노드는 재방문할 필요 없음
		}
	}
	while (!q.empty()) {
		int cur = q.front().first;
		int d = q.front().second;
		q.pop();
		visit[cur] = true;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (!visit[next]) {
				dist[next] = d + 1;
				q.push({ next,d + 1 });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	findCycle(1);
	memset(visit, false, sizeof(visit));
	bfs();
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
}

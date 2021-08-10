#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
#define MAX 1000001
#define INF 987654321
int n, k;
int dist[MAX];
int bfs() {
	queue<int>q;
	q.push(n);
	dist[n] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == k)return dist[k];

		if (cur + 1 < MAX && dist[cur + 1] > dist[cur] + 1) {
			dist[cur + 1] = dist[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && dist[cur - 1] > dist[cur] + 1) {
			dist[cur - 1] = dist[cur] + 1;
			q.push(cur - 1);
		}
		if (cur * 2 < MAX && dist[cur * 2] > dist[cur]) {//0초 후 순간이동
			dist[cur * 2] = dist[cur];
			q.push(cur * 2);
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < MAX; i++) {
		dist[i] = INF;
	}
	cout << bfs();
}

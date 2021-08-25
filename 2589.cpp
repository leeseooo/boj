#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n, m;
char arr[51][51];
bool visit[51][51];
int dist[51][51] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;
void bfs(int a,int b) {
	memset(visit, 0, sizeof(visit));
	memset(dist, 0, sizeof(dist));
	queue<pair<int, int>>q;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n&&ny < m && !visit[nx][ny]) {
				if (arr[nx][ny] == 'L') {
					visit[nx][ny] = true;
					q.push({ nx,ny });
					dist[nx][ny] = dist[x][y] + 1;
					ans = max(ans, dist[nx][ny]);
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}
	cout << ans;
}

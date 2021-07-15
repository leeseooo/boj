#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
int arr[1001][1001];
int visit[1001][1001][2]; //방문한 경로 누적, 벽 부쉈는지 여부
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<pair<int, int>, int>>q;
int bfs() {
	q.push({ {1,1},1 });
	visit[1][1][1] = true;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (y == n && x == m) {
			return visit[y][x][cnt];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 1 && ny >= 1 && nx <= m && ny <= n) {
				if (arr[ny][nx] == 0 && !visit[ny][nx][cnt]) {
					q.push({ {ny,nx} ,cnt });
					visit[ny][nx][cnt] = visit[y][x][cnt] + 1;
				}
				if (arr[ny][nx] == 1 && cnt == 1) {
					visit[ny][nx][cnt - 1] = visit[y][x][cnt] + 1;//현재좌표 경로+1
					q.push({ {ny,nx},cnt - 1 });
				}
			}
		}
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	cout << bfs();
}

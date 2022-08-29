#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
using namespace std;
int n, m, k;
int arr[1000][1000] = { 0, };
bool visit[1000][1000][10]; // 벽 부순 여부 및 방문 체크
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<pair<pair<int, int>, pair<int, int>>>q; // x좌표, y좌표, 부순 벽 개수, 경로 길이
void bfs() {
	q.push({ {0,0},{0,1} });
	visit[0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second.first;
		int dist = q.front().second.second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << dist;
			exit(0);
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (!visit[nx][ny][wall]) {
					// 길인 경우
					if (arr[nx][ny] == 0) {
						q.push({ {nx,ny},{wall,dist + 1} });
						visit[nx][ny][wall] = true;
					}
					// 벽인 경우
					else if(arr[nx][ny] == 1) {
						// k개보다 덜 부수고 왔다면 통과
						if (wall < k) {
							q.push({ {nx,ny},{wall + 1,dist + 1} });
							visit[nx][ny][wall + 1] = true;
						}
					}
				}
			}
		}
	}
	cout <<  -1;
}
void input() {
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	input();
	bfs();
	return 0;
}

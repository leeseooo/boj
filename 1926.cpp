#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
int n, m;
int arr[501][501];
bool visit[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int picture;
void bfs(int x,int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visit[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visit[nx][ny]) {
				if (arr[nx][ny] == 1) {
					q.push({ nx,ny });
					visit[nx][ny] = true;
					picture++;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int maxSize = 0; int picCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && !visit[i][j]) {
				picture = 1; //자기자신
				bfs(i, j);
				maxSize = max(maxSize, picture);
				picCnt++;
			}
		}
	}
	cout << picCnt << "\n" << maxSize;
}

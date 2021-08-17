#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<memory.h>
using namespace std;
int n, m, k;
int arr[101][101];
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>>q;
int ans = 0;
void bfs(int a,int b) {
	int size = 1;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && !visit[nx][ny]) {
				if (arr[nx][ny] == 1) {
					q.push({ nx,ny });
					size++;
					visit[nx][ny] = true;
				}
			}
		}
	}
	ans = max(ans, size);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		arr[r][c] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) {
				memset(visit, false, sizeof(visit));
				bfs(i, j);
			}
		}
	}
	cout << ans;
}

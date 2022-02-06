#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <map>
#include <memory.h> 
using namespace std;
int n, m, t;
int arr[101][101];
bool visit[101][101][2] = { false, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans = 0;
struct pos {
	int x, y, cnt, gram;
};
void bfs() {
	queue<pos>q;
	q.push({ 0,0,0,0 });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int gram = q.front().gram;
		q.pop();
		
		if (arr[x][y] == 2)gram = 1; //검을 먹음
		if (x == n - 1 && y == m - 1) {
			ans = cnt;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (gram == 1) {//검이 있으면 벽 무시
				if (nx >= 0 && ny >= 0 && nx < n&&ny < m && !visit[nx][ny][gram]) {
					q.push({ nx,ny,cnt + 1,gram });
					visit[nx][ny][gram] = cnt + 1;
				}
			}
			else {
				if (nx >= 0 && ny >= 0 && nx < n&&ny < m && !visit[nx][ny][0]) {
					if (arr[nx][ny] != 1) {
						q.push({ nx,ny,cnt + 1,gram });
						visit[nx][ny][0] = cnt + 1;
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	bfs();
	if (ans > 0 && ans <= t)cout << ans;
	else cout << "Fail";
}

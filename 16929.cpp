#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int n, m;
char arr[51][51];
bool visit[51][51] = { false, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sx, sy;
void dfs(int x,int y,int cnt) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0&&ny>=0&&nx<n&&ny<m&&arr[nx][ny] == arr[sx][sy]){
			if (!visit[nx][ny]) {
				dfs(nx, ny, cnt + 1);
			}
			else if (sx == nx && sy == ny && cnt >= 4) {
				cout << "Yes\n";
				exit(0);
			}
		}
	}
	visit[x][y] = false; // 재귀 후 방문 해제
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s = "";
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				sx = i; sy = j;
				dfs(i, j, 1);
				visit[i][j] = true; // 시작점이었던 위치는 방문 체크
			}
		}
	}
	cout << "No\n";
}

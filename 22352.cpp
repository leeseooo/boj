#include <iostream>
#include <algorithm>
#include<queue>
#include<vector>
#include<memory.h>
using namespace std;
int n, m;
int arr[1001][1001];
int pic[1001][1001];
bool visit[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int origin,num,x,y;
void dfs(int x, int y) {
	arr[x][y] = num;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n&&ny < m && !visit[nx][ny] && arr[nx][ny] == origin) {
			visit[nx][ny] = true;
			arr[nx][ny] = num;
			dfs(nx, ny);
		}
	}
}
bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != pic[i][j]) {
				origin = arr[i][j];
				num = pic[i][j];
				x = i; y = j;
				return false;
			}
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> pic[i][j];
		}
	}
	if (check()) {//똑같이 생겼으면 그냥 예스출력
		cout << "YES\n";
		return 0;
	}
	dfs(x,y);
	if (check())cout << "YES\n";
	else cout << "NO\n";
}

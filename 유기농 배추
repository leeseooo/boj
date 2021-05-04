#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
int t, n, m, k;
int arr[1001][1001];
bool visit[1001][1001];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int x, int y) {
	visit[x][y] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < m && ny < n && visit[nx][ny] == false) {
			if(arr[nx][ny]==1)
				dfs(nx, ny);
		}
	}
}
int main() {
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
		}
		int worm = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				//가로세로 배추 심어진 곳 && 방문하지 않은 땅 확인
				if (arr[i][j] == 1 && visit[i][j] == false) {
					dfs(i, j);
					worm++; //한 구역 탐색 후 벌레 수 증가
				}
			}
		}
		cout << worm << "\n";
		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
	}
}

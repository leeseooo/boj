#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<memory.h>
#include<queue>
using namespace std;
int w, h;
int arr[51][51];
bool visit[51][51];
//우,좌,상,하,우상,좌상,우하,좌하
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 }; 
int dy[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int ans = 0;
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visit[nx][ny] && arr[nx][ny] && nx < h && ny < w && nx >= 0 && ny >= 0) {
			//땅인데 방문하지 않았다면
			dfs(nx, ny);
		}
	}
}
int main() {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		//☆★☆★ w가 열 h가 행. 행열 기준으로 배열에 접근하는 것 주의☆★☆★
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}
		ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visit[i][j] && arr[i][j]) {//방문안한 땅일 때
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
	}
}

#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
int n, m;
char arr[251][251];
bool visit[251][251];
int sheep, wolf;
int resS, resW;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
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
			if (nx >= 0 && ny >= 0 && nx < n&&ny < m && !visit[nx][ny]) {
				if (arr[nx][ny] != '#') {
					if (arr[nx][ny] == 'v') {
						wolf++;
					}
					else if (arr[nx][ny] == 'o') {
						sheep++;
					}
					q.push({ nx,ny });
					visit[nx][ny] = true;
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
			if (arr[i][j] == 'o') {
				resS++;
			}
			else if (arr[i][j] == 'v') {
				resW++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'o') {
				sheep = 1, wolf = 0;
				bfs(i, j);
				if (sheep > wolf) {
					resW -= wolf;
				}
				else {
					resS -= sheep;
				}
			}
		}
	}
	cout << resS << " " << resW;
}

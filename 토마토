#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
void bfs();
int M, N;
int v[1001][1001];
queue <pair<int, int>> q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j]; //토마토 위치 입력
			if (v[i][j] == 1) {//익은 토마토이면 큐에 위치 저장
				q.push(make_pair(i, j));
			}
		}
	}
	bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	if (ans > 0)
		cout << ans - 1;//1부터 카운트해줘서 하나 빼줌
	else
		cout << ans;
}
void bfs() { 
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && (v[next_x][next_y] == 0)) {
				v[next_x][next_y] = v[x][y] + 1;//익어가는 과정 저장
				q.push(make_pair(next_x, next_y));
				ans = v[next_x][next_y];
			}
		}
	}
}

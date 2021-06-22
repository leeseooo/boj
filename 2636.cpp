#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
using namespace std;
int n, m;
int arr[101][101];
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int CheezeLeft = 0;
int TimeLeft = 0;

struct pos {//좌표
	int x;
	int y;
};
bool isCheezeEmpty() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}
int countCheeze() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}
void bfs() {
	memset(visit, false, sizeof(visit));

	queue<pos>q;
	q.push({ 0,0 });
	visit[0][0] = true;

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			pos next = cur;
			next.x += dx[i];
			next.y += dy[i];
			if (next.x < n && next.y < m && next.x >= 0 && next.y >= 0 && !visit[next.x][next.y]) {
				if (arr[next.x][next.y] == 0) {//바깥 공기라면
					q.push(next);
				}
				else {//바깥 공기와 닿아있는 치즈라면
					arr[next.x][next.y] = 0; //녹여준다.
				}
				visit[next.x][next.y] = true;
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
	while (1) {
		if (isCheezeEmpty()) break;
		CheezeLeft = countCheeze();//치즈개수 갱신
		bfs();//바깥공기 탐색하면서 공기와 인접한 치즈를 녹인다.
		TimeLeft++;
	}
	cout << TimeLeft << "\n" << CheezeLeft;
}

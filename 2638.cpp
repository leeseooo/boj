#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n, m;
int arr[101][101];
bool visit[101][101];
int outAir[101][101]; //외부 공기 개수
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void input() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}
void bfs() { //외부 공기를 2로 할당해주는 탐색
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		visit[y][x] = true;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				if (arr[ny][nx] == 1) {//현재좌표 y,x가 외부공기이므로 ny,nx가 치즈이면 해당좌표 녹는cnt++
					outAir[ny][nx]++;
				}
				else  if(arr[ny][nx] == 0 && !visit[ny][nx]){//외부공기일때만 큐에 푸시
					q.push({ ny,nx });
				}
				visit[ny][nx] = true;//방문 좌표 체크
			}
		}
	}
}
bool meltCheeze() {
	bool isMelted = false;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (outAir[i][j] >= 2) {
				arr[i][j] = 0;
				isMelted = true;
			}
		}
	}
	return isMelted;
}
void solve() {
	int meltTime = 0;
	while (1) {
		memset(visit, false, sizeof(visit));
		memset(outAir, 0, sizeof(outAir));

		bfs();
		if (!meltCheeze()) break;
		meltTime++;
	}
	cout << meltTime;
}
int main() {
	input();
	solve();
}

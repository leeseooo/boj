#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
int t, n;
int Kx, Ky, Dx, Dy;
bool visit[301][301];
int arr[301][301];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
void bfs(int a,int b) {
	queue<pair<int, int>>q;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == Dx && y == Dy) {//목적지에 도착했을 때 최소이동횟수
			cout << arr[x][y] << "\n";
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < n && ny < n&&nx >= 0 && ny >= 0 && !visit[nx][ny]) {
				visit[nx][ny] = true;
				arr[nx][ny] = arr[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> Kx >> Ky >> Dx >> Dy;
		bfs(Kx,Ky);
		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
	}
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<memory.h>
using namespace std;
int N, K, R, r1, r2, c1, c2;
set<pair<int, int>>s[101][101];
vector<pair<int, int>>cow;
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= N&&ny <= N && !visit[nx][ny]) {
			//다른 소에게로 갈 수 있는 길이 있다면 탐색 후 방문 체크
			//set.count() : vector의 find와 비슷함
			if (s[x][y].count({ nx,ny }))continue;
			dfs(nx, ny);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		s[r1][c1].insert({ r2,c2 });
		s[r2][c2].insert({ r1,c1 });//연결된 길을 양방향으로 저장
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		cow.push_back({ x,y });
	}
	int ans = 0;
	for (int i = 0; i < cow.size(); i++) {
		memset(visit, false, sizeof(visit));
		int x = cow[i].first;
		int y = cow[i].second;
		dfs(x, y);
		for (int j = i + 1; j < cow.size(); j++) {
			int a = cow[j].first;
			int b = cow[j].second;
			if (!visit[a][b])ans++; 
		}
	}
	cout << ans;
}

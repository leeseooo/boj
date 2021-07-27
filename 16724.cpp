#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int parent[1000001];
char arr[1001][1001];
bool visit[1000001];
int find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)return;
	if (x != y) {
		parent[x] = y;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n*m; i++) {//초기화
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int nx = i;
			int ny = j;
			if (arr[i][j] == 'U')nx--;//행
			else if (arr[i][j] == 'D')nx++;
			else if (arr[i][j] == 'L')ny--;//열
			else if (arr[i][j] == 'R')ny++;
			Union(i*m + j, nx*m + ny);//현재노드와 다음노드 병합
		}
	}
	int cnt = 0;
	for (int i = 0; i < n*m; i++) {
		if (!visit[find(i)]) {
			visit[find(i)] = true;
			cnt++;
		}
	}
	cout << cnt;
}

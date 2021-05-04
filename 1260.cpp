#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<memory.h>
using namespace std;
int n, m, v;
bool visited[1001];
int arr[1001][1001];
void dfs(int x) {
	visited[x] = true; //방문
	cout << x << " ";
	for (int i = 1; i <= n; i++) {
		if (arr[x][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
}
void bfs(int x) {
	queue<int>q;
	q.push(x); //시작점 큐에 넣기
	while (!q.empty()) {
		int next = q.front(); //큐의 맨앞 원소를 다음 탐색노드로 설정
		visited[next] = true;//방문했다
		cout << next << " ";
		q.pop(); //방문했으니 팝해주기

		for (int i = 1; i <= n; i++) {
			if (arr[next][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int main() {
	int a, b;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(v);
	cout << "\n";
	memset(visited, false, sizeof(visited));
	bfs(v);
}

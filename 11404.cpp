#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 10000000
int n, m;
int a, b, c;
int graph[101][101];
void floydWarshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
}
void _print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF)
				cout << 0 << " ";
			else
				cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) graph[i][j] = INF; //자기자신 제외 초기화
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (graph[a][b] > c)
			graph[a][b] = c;
	}
	floydWarshall();
	_print();
}

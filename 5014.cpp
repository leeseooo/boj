#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
using namespace std;
int F, S, G, U, D;
int visit[1000001] = { 0, };
int dx[2];
int bfs() {
	queue<int>q;
	q.push(S);
	visit[S] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == G) {
			return visit[cur] - 1;
		}

		for (int i = 0; i < 2; i++) {
			int next = cur + dx[i];
			if (next > 0 && next <= F && !visit[next]) { // OutofBounds 때문에 !visit[next]는 마지막 조건으로 들어가야 함
				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> F >> S >> G >> U >> D;
	dx[0] = U;
	dx[1] = -D;
	int res = bfs();
	if (res == -1) {
		cout << "use the stairs";
	}
	else {
		cout << res;
	}
}

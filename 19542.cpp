#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int n, s, d;
int x, y;
vector<int>v[100001];
bool visit[100001];
int cnt[100001];
int ans = 0;
void solve(int node) {
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (cnt[next] >= d && !visit[next]) {
			ans++;
			visit[next] = true;
			solve(next);
		}
	}
}
int check_leaf(int node) {//현재 위치에서 자식 전체의 깊이를 비교
	int depth = 0;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!visit[next]) {
			visit[next] = true;
			depth = check_leaf(next);
			cnt[node] = max(cnt[node], depth);//갈래가 2개 이상일 때 더 깊은 길이 저장
		}
	}
	return max(cnt[node], depth) + 1;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s >> d;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		v[x].push_back(y); v[y].push_back(x);
	}
	visit[s] = true; //시작 위치 방문
	check_leaf(s);
	memset(visit, false, sizeof(visit));
	visit[s] = true; //시작 위치 방문
	solve(s);
	cout << ((ans+1) * 2 )- 2;
}

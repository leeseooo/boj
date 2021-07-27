#include<iostream>
#include<algorithm>
using namespace std;
int n, m, k;
int parent[1000001];
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
	
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> k;
			if (k == 1) {//연결시키기
				int a = i;
				int b = j;
				a = find(a);
				b = find(b);
				Union(a, b);
			}
		}
	}
	bool flag = false;
	int tmp;
	cin >> tmp;
	int cur = find(tmp);//여행 시작 위치
	for (int i = 1; i < m; i++) {
		cin >> tmp;
		int next = find(tmp);//다음 여행지
		if (cur != next) {//부모가 다르다면 다른 집합이므로 여행할 수 없다.
			flag = true;
			break;
		}
	}
	if (flag) cout << "NO\n";
	else cout << "YES\n";
}

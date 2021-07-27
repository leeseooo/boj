#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int parent[1000001];
int order, a, b;
int find(int x) {
	if (parent[x] == x) return x; //x가 루트노드라면 x를 리턴
	return parent[x] = find(parent[x]);//경로압축(최적화)
}
void Union(int x, int y) {
	x = find(x);
	y = find(y); //루트 노드를 찾는과정

	if (x == y)//같은 집합일땐 합칠필요가 없으므로
		return;
	if (x != y)
		parent[x] = y;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i; //노드 입력
	}
	for (int i = 0; i < m; i++) {
		cin >> order >> a >> b;
		if (order == 0) Union(a, b);
		else if (order == 1) {
			if (find(a) == find(b))//같은집합이라면
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

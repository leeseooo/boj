#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
int n;
int arr[11];
bool visit[11];
bool selected[11];
vector<int>v[11];
int ans = 987654321;
bool isConnected(vector<int>vec, bool flag) { //boolean flag를 이용하여 구역 연결여부를 확인한다.
	queue<int>q;
	q.push(vec[0]);
	visit[vec[0]] = true;
	int cntNode = 1;

	while (!q.empty()) {
		int s = q.front();
		q.pop();
		for (auto i : v[s]) {
			if (selected[i] == flag && !visit[i]) {
				q.push(i);
				cntNode += 1;
				visit[i] = true;
			}
		}
	}
	memset(visit, false, sizeof(visit));
	if (cntNode == vec.size())return true;
	return false;
}
bool checkArea() { //구역을 두개로 나누고 연결되었는지 확인한다.
	vector<int>a; vector<int>b;
	for (int i = 1; i <= n; i++) {
		if (selected[i] == true)a.push_back(i);
		else b.push_back(i);
	}
	if (a.empty() || b.empty())return false;
	if (isConnected(a, true) == false)return false;
	if (isConnected(b, false) == false)return false;
	return true;
}
void solve() { //각 구역 인구 차이의 최솟값을 구한다.
	int a = 0; int b = 0;
	for (int i = 1; i <= n; i++) {
		if (selected[i] == true)a += arr[i];
		else b += arr[i];
	}
	ans = min(ans, abs(a - b));
}
void search(int idx,int depth) { //중복되지 않도록 조합으로 구역을 나눈다.
	if (depth >= 1) {
		if (checkArea() == true) {
			solve();
		}
	}
	for (int i = idx; i <= n; i++) {
		if (!selected[i]) {
			selected[i] = true;
			search(i + 1, depth + 1);
			selected[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}
	search(1, 0);
	if (ans == 987654321)cout << -1;
	else cout << ans;
}

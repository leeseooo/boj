#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <map>
#include <memory.h> 
using namespace std;
int n, k;
int arr[11];
map<string, bool>m;
string tmp = "";
bool visit[11];
void recur(int cnt) {
	if (cnt == k) {
		m[tmp] = true;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			tmp += to_string(arr[i]);
			recur(cnt + 1);
			int idx = tmp.size() - to_string(arr[i]).size();
			tmp.erase(idx, tmp.size());
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	recur(0);
	int ans = 0;
	for (auto i : m) {
		if (i.second) {
			ans++;
		}
	}
	cout << ans;
}

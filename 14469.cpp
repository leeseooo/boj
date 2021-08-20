#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<memory.h>
using namespace std;
int n;
vector<pair<int, int>>v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, t;
		cin >> a >> t;
		v.push_back({ a,t });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int start = v[i].first;
		int finish = v[i].second;
		if (start >= ans) {
			ans = start + finish;
		}
		else {
			ans += finish;
		}
	}
	cout << ans;
}

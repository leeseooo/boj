#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int ans = 987654321;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	vector<pair<int,int>>v;
	for (int i = 0; i < n; i++) {
		int t, s;
		cin >> t >> s;
		v.push_back({ s,t });//끝나는 시간 오름차순으로 정렬
	}
	sort(v.begin(), v.end());
	//끝내야하는 시간이 큰 것부터
	for (int i = n - 1; i >= 0; i--) {//i번째 일 끝나는 시간 - 소요시간 
		ans = min(ans, v[i].first);
		ans -= v[i].second;
	}
	if (ans < 0)cout << -1;
	else cout << ans;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k, m;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k >> m;
	int low = 1;
	int high = 1e9;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 2 * k) {//양쪽꼬다리
			v.push_back(tmp - 2 * k);
		}
		if (tmp > k && tmp < 2 * k) {//한쪽꼬다리 && k보다 클 때만
			v.push_back(tmp - k);
		}
	}
	int ans = -1; //만족하는 김밥이 없을 경우를 위해 -1로 초기화
	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 0;
		for (int i : v) {
			cnt += i / mid;
		}
		if (cnt >= m) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << ans;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int maxSize = 0;
	vector<int>ans;
	for (int i = n / 2; i <= n; i++) {
		vector<int>v;
		v.push_back(n);
		v.push_back(i);
		int idx = 0;
		while (1) {
			if (v[idx] - v[idx + 1] >= 0) {
				v.push_back(v[idx] - v[idx + 1]);
				idx++;
			}
			else break;
		}
		if (v.size() > maxSize) {
			maxSize = v.size();
			ans = v;
		}
	}
	cout << maxSize << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}

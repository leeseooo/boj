#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
int n, a, b, c;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	cin >> b >> c;

	long long cnt = 0;
	for (auto i : v) {
		i -= b;
		if (i <= 0)cnt++;
		else {
			cnt++;
			cnt += ceil((double)i / (double)c);
		}
	}
	cout << cnt;
}

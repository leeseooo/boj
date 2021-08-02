#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int n;
vector<int>v;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > v.back()) {
			v.push_back(num);
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
			v[idx] = num;
		}
	}
	cout << v.size() - 1;
}

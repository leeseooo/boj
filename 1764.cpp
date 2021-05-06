#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<string>v;
bool search(int low, int high, string str) {
	if (high < low) return false;
	else {
		int mid = (low + high) / 2;
		if (v[mid] == str) return true;
		else if (v[mid] > str) return search(low, mid - 1, str);
		else return search(mid + 1, high, str);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end());

	vector<string>ans;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (search(0, n - 1, str)) {
			ans.push_back(str);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}

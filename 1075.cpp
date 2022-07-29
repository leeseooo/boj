#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
int n, f;
vector<string>v;
void init() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			string str = "";
			str.push_back(i + '0');
			str.push_back(j + '0');
			v.push_back(str);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> f;
	string tmp = to_string(n);
	tmp = tmp.substr(0, tmp.size() - 2);
	init();
	vector<string>ans;
	for (int i = 0; i < v.size(); i++) {
		string str = tmp + v[i];
		int num = stoi(str);
		if (num % f == 0) {
			ans.push_back(v[i]);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0];
}

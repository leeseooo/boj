#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
int n, m;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	map<string, vector<string>>idol;
	for (int i = 0; i < n; i++) {
		string team;
		int cnt;
		cin >> team >> cnt;
		for (int j = 0; j < cnt; j++) {
			string member;
			cin >> member;
			idol[team].push_back(member);
		}
	}
	for (int i = 0; i < m; i++) {
		string name;
		int type;
		cin >> name >> type;
		if (type == 0) {
			vector<string>v;
			for (auto &it : idol) {
				if (it.first == name) {
					for (int i = 0; i < it.second.size(); i++) {
						v.push_back(it.second[i]);
					}
				}
			}
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << '\n';
			}
		}
		else {
			bool flag = false;
			for (auto &it : idol) {
				for (int i = 0; i < it.second.size(); i++) {
					if (name == it.second[i]) {
						cout << it.first << '\n';
						flag = true;
						break;
					}
				}
				if (flag)break;
			}
		}
	}
}

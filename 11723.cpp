#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
int m;
vector<int>v;
string s;
int num;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s == "add") {
			cin >> num;
			auto it = find(v.begin(), v.end(), num);
			if (it != v.end())continue;
			else {
				v.push_back(num);
			}
		}
		else if (s == "remove") {
			cin >> num;
			auto it = find(v.begin(), v.end(), num);
			if (it != v.end()) {
				int idx = 0;
				for (int i = 0; i < v.size(); i++) {
					if (v[i] == num)idx = i;
				}
				v.erase(v.begin() + idx, v.begin() + idx + 1);
			}
			else continue;
		}
		else if (s == "check") {
			cin >> num;
			auto it = find(v.begin(), v.end(), num);
			if (it != v.end())cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> num;
			auto it = find(v.begin(), v.end(), num);
			if (it != v.end()) {
				int idx = 0;
				for (int i = 0; i < v.size(); i++) {
					if (v[i] == num)idx = i;
				}
				v.erase(v.begin() + idx, v.begin() + idx + 1);
			}
			else {
				v.push_back(num);
			}
		}
		else if (s == "all") {
			v = vector<int>(20);
			for (int i = 0; i < 20; i++) {
				v[i] = i + 1;
			}
		}
		else if (s == "empty") {
			v.clear();
		}
	}
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <regex>
#include <map>
#include <memory.h>
using namespace std;
int getTime(string s) {
	string h = s.substr(0, 2);
	string m = s.substr(3, 2);
	return ((stoi(h) * 60) + stoi(m));
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string S, E, Q;
	cin >> S >> E >> Q;
	int startTime = getTime(S);
	int endTime = getTime(E);
	int quitTime = getTime(Q);
	cin.ignore();

	string str;
	map<string, int>list;

	while (getline(cin, str)) {
		if (str == "\0")break;
		int t = getTime(str.substr(0, 5));
		string name = str.erase(0, 6);

		if (!list[name]) {
			if (t <= startTime && t >= 0) {
				list[name]++;
			}
		}
		else if (list[name]) {
			if (t >= endTime && t <= quitTime) {
				list[name]++;
			}
		}
	}
	int ans = 0;
	for (auto p : list) {
		if (p.second > 1) {
			ans++;
		}
	}
	cout << ans << '\n';
}

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
string ans;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	string s;
	cin >> s;
	ans = s;
	for (int i = 1; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < s.length(); j++) {
			if (tmp[j] != s[j]) {
				ans[j] = '?';
			}
		}
	}
	cout << ans;
}

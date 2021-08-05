#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
string ans;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	int cnt = 0;
	int i = 0;
	while(i<s.length()) {
		while (s[i] == 'X') {
			cnt++;
			i++;
		}
		if (cnt % 2 == 0) {
			while (cnt >= 4) {
				ans += "AAAA";
				cnt -= 4;
			}
			while (cnt >= 2) {
				ans += "BB";
				cnt -= 2;
			}
		}
		if (cnt != 0) {
			cout << -1;
			return 0;
		}
		if (s[i] == '.') {
			ans += '.';
			i++;
		}
	}
	cout << ans;
}

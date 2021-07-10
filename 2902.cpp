#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string str;
	cin >> str;
	string ans;
	ans += str[0];
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == '-') {
			ans += str[i + 1];
		}
	}
	cout << ans;
}

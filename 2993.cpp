#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string str, ans;
int len;
void divide(string s, int first, int second) {
	string a, b, c;
	a = b = c = "";
	for (int i = 0; i <= first; i++) a += s[i];
	for (int i = first + 1; i <= second; i++)b += s[i];
	for (int i = second + 1; i < len; i++)c += s[i];
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(c.begin(), c.end());

	string result = a + b + c;
	if (ans == "") ans = result;
	else {
		if (ans > result) ans = result;
	}
}
int main() {
	cin >> str;
	len = str.length();
	for (int i = 0; i < len - 2; i++) {
		for (int j = i; j < len - 1; j++) {
			if (i >= j) continue;
			string tmp = str;
			divide(tmp, i, j);
		}
	}
	cout << ans;
}

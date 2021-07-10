#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	int len = s.length();
	string str[1001];
	for (int i = 0; i < len; i++) {
		str[i] = s.substr(i, len);//substr()
	}
	sort(str, str + len);
	for (int i = 0; i < len; i++) {
		cout << str[i] << "\n";
	}
}

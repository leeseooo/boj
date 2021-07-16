#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int main() {
	cin >> s;
	int len = s.length();
	bool flag = false;
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += s[i] - '0';
		if (s[i] - '0' == 0) flag = true;
	}
	if (sum % 3 != 0 || flag == false) {
		cout << -1 << "\n";
		return 0;
	}
	sort(s.begin(), s.end(), greater<>());
	cout << s;
}

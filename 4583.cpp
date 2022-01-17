#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	char arr[10] = "iovwxbdpq";
	string tmp;
	while (1) {
		cin >> s;
		if (s == "#")break;
		bool flag;
		for (int i = 0; i < s.length(); i++) {
			flag = false;
			for (int j = 0; j < 9; j++) {
				if (s[i] == arr[j]) { 
					flag = true; 
					break;
				}
			}
			if (!flag) {
				cout << "INVALID\n";
				break;
			}
			else {
				if (s[i] == 'b')s[i]= 'd';
				else if (s[i] == 'd')s[i] = 'b';
				else if (s[i] == 'q')s[i] = 'p';
				else if (s[i] == 'p')s[i] = 'q';
			}
		}
		if (flag) {
			tmp = s;
			reverse(tmp.begin(), tmp.end());
			cout << tmp << '\n';
			tmp.clear();
		}
	}
	return 0;
}

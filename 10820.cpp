#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (getline(cin,s)) {
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				b++;
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				a++;
			}
			else if (s[i] == ' ') {
				d++;
			}
			else {
				c++;
			}
		}
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}
}

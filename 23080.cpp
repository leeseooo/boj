#include <iostream>
#include<string>
using namespace std;
int n;
string s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i % n == 0) {
			cout << s[i];
		}
	}
}

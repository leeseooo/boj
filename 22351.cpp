#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string s;
int a, b;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	string tmp;
	int a_tmp = 1;
	a = 1;
	while (1) {
		if (tmp.length() < s.length()) {
			tmp += to_string(a_tmp++);
		}
		else if (tmp.length() > s.length()) {
			tmp = "";
			a_tmp = ++a;
		}
		else if(tmp.length() == s.length()){
			if (tmp.compare(s) == 0) {
				b = a_tmp - 1;
				break;
			}
			else if(tmp.compare(s) != 0){
				tmp = "";
				a_tmp = ++a;
			}
		}
	}
	cout << a << " " << b;
}

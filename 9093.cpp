#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int t;
string str;
int main() {
	cin >> t;
	cin.ignore();
	while (t--) {
		getline(cin, str);
		int idx = str.length();
		for (int i = str.length() - 1; i >= 0; i--) {
			if (str[i] == ' ') {
				reverse(str.begin()+i+1, str.begin()+idx);
				idx = i;
			}
			else if (i == 0) {
				reverse(str.begin(), str.begin() + idx);
			}
		}
		cout << str << "\n";
	}
}

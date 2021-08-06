#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	getline(cin, s);
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'U' && cnt == 0) cnt = 1;
		else if (s[i] == 'C' && cnt == 1) cnt = 2;
		else if (s[i] == 'P' && cnt == 2) cnt = 3;
		else if (s[i] == 'C' && cnt == 3) {
			cnt = 4;
			break;
		}
	}
	if (cnt == 4)cout << "I love UCPC";
	else cout << "I hate UCPC";
}
//testcase : UUPPPCCCCUUUPPCC 

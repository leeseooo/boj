#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
#include<memory.h>
#include<stack>
using namespace std;
int main() {
	stack<int>st;
	int bp = 0;
	int sp = 0;
	string s;
	while (1) {
		getline(cin, s);
		if (s == ".") {
			break;
		}
		bool flag = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '[') {
				st.push(s[i]);
				bp++;
			}
			else if (s[i] == '(') {
				st.push(s[i]);
				sp++;
			}
			else if (s[i] == ']') {
				if (st.empty() || st.top() != '[') {
					flag = false;
					break;
				}
				st.pop();
				bp--;
			}
			else if (s[i] == ')') {
				if (st.empty() || st.top() != '(') {
					flag = false;
					break;
				}
				st.pop();
				sp--;
			}
		}
		if (flag) {
			if (sp || bp) {
				cout << "no\n";
			}
			else cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
		while (!st.empty()) {
			st.pop();
		}
		sp = 0, bp = 0;
	}
}

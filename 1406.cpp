#include <iostream>
#include <algorithm>
#include <stack>
#include<string>
using namespace std;
int n;
string str;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> str;
	cin >> n;
	stack<char>left, right;
	for (int i = 0; i < str.length(); i++)left.push(str[i]);
	for (int i = 0; i < n; i++) {
		char op;
		cin >> op;
		if (op == 'P') {
			char c;
			cin >> c;
			left.push(c);
		}
		else if (op == 'L') {
			if (left.empty())continue;
			right.push(left.top());
			left.pop();
		}
		else if (op == 'D') {
			if (right.empty())continue;
			left.push(right.top());
			right.pop();
		}
		else if (op == 'B') {
			if (left.empty())continue;
			left.pop();
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
}

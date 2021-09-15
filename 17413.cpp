#include <iostream>
#include <algorithm>
#include <string>
#include<stack>
using namespace std;
string str;
stack<char>st;
void print() {
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	getline(cin, str);
	bool flag = false;
	for (char c : str) {
		if (c == '<') {
			print();
			flag = true;
			cout << c;
		}
		else if (c == '>') {
			flag = false;
			cout << c;
		}
		else if (c == ' ') {
			print();
			cout << ' ';
		}
		else if (flag) {
			cout << c;
		}
		else if (!flag) {
			st.push(c);
		}
	}
	print();
}

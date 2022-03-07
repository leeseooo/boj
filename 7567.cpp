#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <map>
#include <memory.h> 
using namespace std;
string s;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	int sum = 10;
	char tmp = s[0];
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == tmp) {//같은 방향인 경우
			sum += 5;
		}
		else {
			sum += 10;
			if (tmp == '(')tmp = ')';
			else tmp = '(';
		}
	}
	cout << sum;
}

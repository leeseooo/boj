#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <map>
#include <memory.h> 
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int aSize = a.size();
	int bSize = b.size();
	int c = 0;//carry
	string ans = "";
	while (aSize > 0 || bSize > 0) {
		int atmp = 0, btmp = 0;
		if (aSize > 0) {
			atmp = a[--aSize] - '0';
		}
		if (bSize > 0) {
			btmp = b[--bSize] - '0';
		}
		int sum = atmp + btmp + c;
		c = sum / 10;
		ans += to_string(sum % 10); //1의 자리만 더함
	}
	if (c > 0) {//마지막 계산
		ans += to_string(c);
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}

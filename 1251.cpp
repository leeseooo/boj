#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str, ans;
int len;
void divide(string str, int first, int second) {
	string a, b, c;
	a = b = c = ""; //임의의 3개 문자열

	for (int i = 0; i <= first; i++) a += str[i];
	for (int i = first + 1; i <= second; i++) b += str[i];
	for (int i = second + 1; i < len; i++) c += str[i];
	//세 부분으로 나눈 문자열을 뒤집어준다.
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(c.begin(), c.end());

	string res = a + b + c;
	if (ans == "")ans = res; //처음 한번은 초기화
	else {
		if (ans > res) ans = res;
	}
}
int main() {
	cin >> str;
	len = str.length();
	for (int i = 0; i < len - 1; i++) {
		for (int j = i; j < len - 1; j++) {
			if (i >= j) continue;
			string tmp = str;
			divide(tmp, i, j);
		}
	}
	cout << ans;
}

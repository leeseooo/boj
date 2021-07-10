#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a, b;
int main() {
	cin >> a >> b;
	int ans = 50;
	int a_len = a.length(); int b_len = b.length();
	for (int i = 0; i <= b_len - a_len; i++) { //두 문자열 길이 차이만큼 a에서 한칸씩 옮기며 비교
		int cnt = 0;
		for (int j = 0; j < a_len; j++) {
			if (a[j] != b[i + j]) cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}

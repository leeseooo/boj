#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int l, c;
char alp[16];
void solve(string ans,int mo,int za, int cnt) {//cnt는 한 알파벳 중복사용 방지를 위함
	if (ans.size() == l) {
		if (mo >= 1 && za >= 2) {
			cout << ans << "\n";
		}
		return;
	}
	for (int i = cnt; i < c; i++) {
		if (alp[i] == 'a' || alp[i] == 'e' || alp[i] == 'i' || alp[i] == 'o' || alp[i] == 'u') {
			solve(ans + alp[i], mo + 1, za,i+1);
		}
		else {
			solve(ans + alp[i], mo, za + 1,i+1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> l >> c;
	//if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	for (int i = 0; i < c; i++) {
		cin >> alp[i];
	}
	// a i / c s t w
	sort(alp, alp + c);
	solve("", 0, 0,0);
}

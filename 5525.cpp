#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
string s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> s;

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		if (s[i] == 'O')continue;
		else {
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				tmp++;
				if (tmp == n) {
					tmp--;
					ans++;
				}
				i += 2;
			}
		}
	}
	cout << ans;
}

/* 50점 코드 -> substr을 일일이 비교하면 O(n^2) 걸려서 시간초과
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
string s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> s;
	string p;
	for (int i = 0; i < n; i++) {
		p += "IO";
	}
	p += "I";
	int idx = 0;
	int ans = 0;
	while (idx < m) {
		if (s[idx] == 'I') {
			if (idx + n * 2 + 1 > m)break;
			string tmp = "";
			for (int i = idx; i < idx + n * 2; i++) {
				tmp += s[i];
			}
			tmp += s[idx + n * 2];
			if (tmp == p) {
				ans++;
			}
		}
		idx++;
	}
	cout << ans;
}
*/

#include <iostream>
#include<algorithm>
using namespace std;
int tc;
int ans = 1000;
void recursion(int s, int t, int cnt) {
	int mycnt = cnt + 1;
	if (s < t) {
		recursion(s + 1, t, mycnt);
		recursion(s * 2, t + 3, mycnt);
	}
	if (s > t) {
		return;
	}
	if (s == t) {
		ans = min(ans, mycnt);
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> tc;
	while (tc--) {
		ans = 1000;
		int s, t;
		cin >> s >> t;
		recursion(s, t, -1);
		cout << ans << '\n';
	}
}

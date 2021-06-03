#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int m, n;
bool prime[10001];
int main() {
	cin >> m >> n;
	for (int i = 2; i <= n; i++) {
		prime[i] = true;
	}
	prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
	int sum = 0;
	int ans = 10001;
	for (int i = m; i <= n; i++) {
		if (prime[i]) {
			sum += i;
			ans = min(ans, i);
		}
	}
	if (sum)
		cout << sum << "\n" << ans;
	else
		cout << "-1";
}

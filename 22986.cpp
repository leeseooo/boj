#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int t;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		unsigned long long n, k, tmp, sum;
		cin >> n >> k;
		if (k >= n) tmp = 0;
		else tmp = (n - k - 1)*(n - k) / 2;
		sum = n * (n + 1) / 2 - tmp;
		cout << sum * 4 << '\n';
	}
}

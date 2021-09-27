#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, b;
int arr[501][501];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 1e9;
	int ansHeight = 0;
	for (int i = 0; i <= 256; i++) {
		int high = 0; int low = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[j][k] > i)high += arr[j][k] - i;
				else if (arr[j][k] < i)low += i - arr[j][k];
			}
		}
		if (low <= high + b) {
			int ttime = high * 2 + low;
			if (ans >= ttime) {
				ans = ttime;
				ansHeight = i;
			}
		}
	}
	cout << ans << ' ' << ansHeight;
}

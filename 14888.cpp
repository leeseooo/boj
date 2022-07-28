#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
int n;
int num[11];
int op[4];
int maxVal = -987654321;
int minVal = 987654321;
void solve(int idx, int tmp) {
	if (idx == n) {
		if (tmp > maxVal)maxVal = tmp;
		if (tmp < minVal) minVal = tmp;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i] -= 1;
			if (i == 0) {
				solve(idx + 1, tmp + num[idx]);
			}
			else if (i == 1) {
				solve(idx + 1, tmp - num[idx]);
			}
			else if (i == 2) {
				solve(idx + 1, tmp * num[idx]);
			}
			else {
				solve(idx + 1, tmp / num[idx]);
			}
			op[i] += 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	solve(1, num[0]);
	cout << maxVal << '\n' << minVal;
}

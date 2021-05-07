#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, x;
	cin >> n;
	int num[100001];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> x;
	sort(num, num + n);

	int low = 0; int high = n - 1;
	int ans = 0;
	while (high>low) {
		int tmp = num[low] + num[high];
		if (tmp == x) {
			low++;
			high--;
			ans++;
		}
		else if (tmp > x) {
			high--;
		}
		else low++;
	}
	cout << ans;
}

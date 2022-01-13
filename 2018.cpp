#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int low = 1;
	int high = 1;
	int cnt = 0;
	int sum = 0;
	while (1) {
		if (sum >= n) {
			sum -= low++;
		}
		else if (high == n + 1)break;
		else {
			sum += high++;
		}
		if (sum == n)cnt++;
	}
	cout << cnt;
}

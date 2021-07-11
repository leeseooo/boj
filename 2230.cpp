#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
int arr[100001];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int start = 0, end = 0;
	int ans = 2000000001;
	while (start <= end && start < n && end < n) {
		int tmp = arr[end] - arr[start];
		if (tmp < m) {
			end++;
		}
		else if (tmp > m) {
			ans = min(ans, tmp);
			start++;
		}
		else if (tmp == m) { 
			ans = m;
			break;
		}
	}
	cout << ans;
}

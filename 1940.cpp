#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[15001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int low = 0;
	int high = n - 1;
	int cnt = 0;
	while (low < high) {
		int sum = arr[low] + arr[high];
		if (sum == m) {
			low++; high--; cnt++;
		}
		else if (sum > m) {
			high--;
		}
		else low++;
	}
	cout << cnt;
}

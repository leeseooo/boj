#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int arr[10001];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int high = 0;
	int low = 0;
	int sum = arr[0];
	int cnt = 0;
	while (low <= high && high < n) {
		if (sum < m) {
			high++;
			sum += arr[high];
		}
		else if (sum == m) {
			cnt++;
			high++;
			sum += arr[high];
		}
		else if (sum > m) {
			sum -= arr[low];
			low++;
			if (low > high) {// low가 high보다 커지면 거기부터 다시시작
				high = low;
				sum = arr[low];
			}
		}
	}
	cout << cnt;
}

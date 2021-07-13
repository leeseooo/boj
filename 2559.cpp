#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int arr[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = -987654321;
	int start = 0;
	int end = 0;
	int sum = 0;
	while (start <= end && end < n) {
		sum += arr[end++];
		if (end - start == k) {
			ans = max(ans, sum);
			sum -= arr[start++];
		}
	}
	cout << ans;
}

/* 
//틀렸던 코드. sum을 미리 배열값 한개 할당해놓고 end를 움직여서 틀렸나보다
#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int arr[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += arr[i];
	}
	int start = 0;
	int end = 0;
	int sum = arr[0];
	while (start <= end && end < n) {
		sum += arr[++end];
		if (end - start + 1 == k) {
			ans = max(ans, sum);
			sum -= arr[start++];

		}
	}
	cout << ans;
}
*/

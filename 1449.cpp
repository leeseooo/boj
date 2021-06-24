#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;
int n, l;
int arr[1001];
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int start = arr[0];
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int term = arr[i] - start;
		if (term <= l - 1) {
			continue;
		}
		else {
			ans++;//테이프 하나로 거리가 안된다면 개수증가, 시작점 교체
			start = arr[i];
		}
	}
	cout << ans;
}

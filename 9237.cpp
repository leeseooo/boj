#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<>());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, arr[i] + (i + 1));//나무 자라는데 걸리는 시간 + 현재 날짜
	}
	cout << ans + 1;//다 자라고 나서 이장님 불러
}

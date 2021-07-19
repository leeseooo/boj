#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N, K, B;
bool arr[100001];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	memset(arr, false, sizeof(arr));
	cin >> N >> K >> B;
	int num;
	for (int i = 0; i < B; i++) {
		cin >> num;
		arr[num] = true; //고장
	}
	int cnt = 0;
	for (int i = 1; i <= K; i++) {
		cnt += arr[i];
	}
	int ans = cnt;
	int j = 1;
	for (int i = K + 1; i <= N; i++) {
		cnt += arr[i]; cnt -= arr[j++];
		ans = min(ans, cnt);
	}
	cout << ans;
}

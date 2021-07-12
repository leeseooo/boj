#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	int arr[100001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int start = 0;
	int end = 0;
	int sum = arr[0];
	int ans = 100001;
	while (start <= end && end < n) {
		if (sum >= s) {
			ans = min(ans, end - start+1);
			sum -= arr[start++];
		}
		else if (sum < s) {
			sum += arr[++end];
		}
	}
	if(ans != 100001)
		cout << ans;
	else cout << 0;
}

/* 처음에 시간초과 났던 코드
// sum >= s 일 때 end에 start를 할당해주는 부분에서 틀린듯
// end를 다시 start지점으로 보내면 그만큼 다시 연산해야 하니까
// 그러지말고 위의 코드처럼 end는 그대로 놔두고
// arr[start] 값만 감소시키고 슬라이딩 윈도우 방식으로 해결할 수 있다.
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	int arr[100001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int start = 0;
	int end = 0;
	int sum = arr[0];
	int ans = 100001;
	while (start <= end && end < n) {
		if (sum < s) {
			end++;
			sum += arr[end];
		}
		else if (sum >= s) {
			ans = min(ans, end - start + 1);
			start++;
			end = start;
			sum = arr[start];
		}
	}
	if(ans != 100001)
		cout << ans;
	else cout << 0;
}*/

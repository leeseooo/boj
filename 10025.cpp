#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
long long n, k;
long long arr[10000001]; //배열 크기 이만큼은 해줘야 OutOfBounds를 통과하네
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	long long _max = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		_max = max(_max, (long long)b);
		arr[b] = a;
	}
	long long sum = 0;
	long long window = 2 * k + 1;
	for (int i = 0; i < window; i++) {
		sum += arr[i]; //init
	}
	long long ans = sum; //0부터 윈도우 크기까지
	for (long long i = window; i <= _max; i++) { //윈도우크기부터 끝까지 탐색
		sum += arr[i] - arr[i - window]; //다음 값 더하고 맨앞의 값 빼준다
		ans = max(ans, sum); //최댓값 갱신
	}
	cout << ans;
}

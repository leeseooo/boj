#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, c, low, mid, high, cnt, tmp, ans, d;
int home[200001];
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> home[i];
	}
	sort(home, home + n);

	low = 1;//최소거리
	high = home[n - 1] - home[0]; //최대거리

	while (low <= high) {
		cnt = 1; //공유기 간 거리를 최대로 하려면 첫번째 집에는 설치되어야 함
		tmp = home[0];
		mid = (high + low) / 2;

		for (int i = 1; i < n; i++) {
			d = home[i] - tmp;
			if (mid <= d) {
				cnt++;
				tmp = home[i];
			}
		}
		if (cnt >= c) {//계산된 공유기 수 >= 설치할 공유기 수
			ans = mid;
			low = mid + 1; //공유기 간 간격을 늘린다.
		}
		else
			high = mid - 1; //공유기 간 간격을 줄인다.
	}
	cout << ans;
}

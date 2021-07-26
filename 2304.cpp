#include<iostream>
#include<algorithm>
using namespace std;
int n;
int max_height, min_height,max_height_idx;
int arr[1001];
int left_sum() {
	int sum = 0;
	int h = 0;
	for (int i = min_height; i < max_height_idx; i++) {//가장 높은 기둥 전까지 좌->우 합 구하기
		h = max(h, arr[i]);//h보다 더 높은 기둥이 있다면 갱신, 아니면 그대로 수직으로 이동
		sum += h;
	}
	return sum;
}
int right_sum() {
	int sum = 0;
	int h = 0;
	//가장 높은 기둥이 있는 곳 전까지 우->좌 합 구하기
	for (int i = max_height; i > max_height_idx; i--) {
		h = max(h, arr[i]);
		sum += h;
	}
	return sum;
}
void solve() {
	int ans = arr[max_height_idx]; //가장 높은 기둥은 자기 머리만 덮으면 됨
	ans += left_sum() + right_sum();
	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cin >> arr[x];
		//가장 왼쪽 인덱스,가장 마지막 인덱스 찾기
		max_height = max(max_height, x);
		min_height = min(min_height, x);
		//가장 높은 기둥의 인덱스 저장
		if (arr[x] > arr[max_height_idx]) {
			max_height_idx = x;
		}
	}
	solve();
}

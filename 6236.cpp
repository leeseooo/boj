#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, k;
int arr[100001];
int sum = 0;
bool check(int mid) {
	int tmp = mid;
	int num = 1;
	for (int i = 0; i < n; i++) {
		if (mid < arr[i]) return false;
		//남은 금액이 그날 사용 금액보다 많더라도 남은 금액은 다시 통장에 집어넣고 k원만큼 인출하기 때문에
		//인출금액이 하루치보다 적으면 무조건 false
		if (tmp - arr[i] < 0) {
			tmp = mid; //남은금액 통장에 집어넣고 다시 k원만큼 인출
			num++; //인출횟수 증가
		}
		tmp -= arr[i];
	}
	return m >= num;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int high = sum;
	int low = 1;
	int res = 0;
	while (high >= low) {
		int mid = (high + low) / 2;
		if (check(mid)) {
			res = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << res;
}

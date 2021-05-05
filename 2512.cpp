#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<int>v;
int search(int low, int high) {
	int sum;
	int mid = (high + low) / 2;
	while (high>=low) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += v[i] > mid ? mid : v[i];
		}
		if (sum == m)
			return mid;
		if (sum > m) high = mid - 1; //상한가 낮추기
		else low = mid + 1; //상한가 높이기

		mid = (high + low) / 2;
	}
	return mid;
}
int main() {
	scanf("%d", &n);
	int high = 0;
	v = vector<int>(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end(), greater<int>());
	high = v.front();//가장 큰 금액
	scanf("%d", &m);
	printf("%d", search(0, high));
}

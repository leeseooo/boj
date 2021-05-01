#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int card[500001], arr[500001];
int flag = 0;
int lowerBinary(int *arr, int target, int size) {
	int start = 0, end = size - 1;
	int mid;
	while (end > start) {
		mid = (start + end) / 2;
		if (arr[mid] >= target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}
int upperBinary(int* arr, int target, int size) {
	int start = 0, end = size - 1;
	int mid;
	while (end > start) {
		mid = (start + end) / 2;
		if (arr[mid] > target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}
int main() {
	int n, m, lower, upper;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	sort(card, card + n);
	for (int i = 0; i < m; i++) {
		lower = lowerBinary(card, arr[i], n);
		upper = upperBinary(card, arr[i], n);
		if (upper == n - 1 && card[n - 1] == arr[i])//마지막 인덱스인데 찾고자하는값과 같다면 +1
			upper++;
		cout << upper - lower << " ";
	}
}

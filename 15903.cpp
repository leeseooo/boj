#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int n, m;
long long arr[1001];
long long sum = 0;//1,000,000 * 1,000 = 1,000,000,000 돼서 long long으로 해줘야하는듯
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		sort(arr, arr + n);
		long long tmp = arr[0] + arr[1];
		arr[0] = tmp;
		arr[1] = tmp;
	}
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	cout << sum;
}

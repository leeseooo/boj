#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory.h>
#include<queue>
using namespace std;
int n;
long long len[100001] = { 0, };
long long price[100001] = { 0, };
long long sum = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> len[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	long long tmp = price[0];
	for (int i = 0; i < n - 1; i++) {
		if (price[i] < tmp) {
			tmp = price[i]; //더 싼 기름값 저장
		}
		sum += tmp * len[i]; //기름값*거리
	}
	cout << sum;
}

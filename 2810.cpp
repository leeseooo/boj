#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;
int n;
char arr[51];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'S') {
			cnt++;
		}
		else if (arr[i] == 'L') {
			i++; cnt++;
		}
	}
	if (cnt <= n) {
		cout << cnt;
	}
	else {
		cout << n;
	}
}

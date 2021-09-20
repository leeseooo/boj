#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
using namespace std;
int n;
char arr[51][51];
int ans = 0;
void check() {
	for (int i = 0; i < n; i++) {
		char c = arr[i][0];
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == c) cnt++;
			else cnt = 1;
			c = arr[i][j];
			if (cnt > ans)ans = cnt;
		}
	}
	for (int j = 0; j < n; j++) {
		char c = arr[0][j];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i][j] == c)cnt++;
			else cnt = 1;
			c = arr[i][j];
			if (cnt > ans)ans = cnt;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {//행 기준 가장 긴 사탕 탐색
		for (int j = 0; j < n - 1; j++) {
			swap(arr[i][j], arr[i][j + 1]);
			check();
			swap(arr[i][j], arr[i][j + 1]);//복구
		}
	}
	for (int j = 0; j < n; j++) {//열 기준 가장 긴 사탕 탐색
		for (int i = 0; i < n - 1; i++) {
			swap(arr[i][j], arr[i + 1][j]);
			check();
			swap(arr[i][j], arr[i + 1][j]);
		}
	}
	cout << ans;
}

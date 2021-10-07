#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int n, m;
int arr[51][51];
int ans = 1;
int solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int size = 1;
			while (1) {
				if (i + size >= n || j + size >= m)break;
				int num = arr[i][j];
				int p1 = arr[i + size][j], p2 = arr[i][j + size], p3 = arr[i + size][j + size];
				size++;
				if (num==p1 && num==p2 && num==p3) {
					ans = max(ans, size*size);
				}
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) { 
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	cout << solve();
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
int n, m, k;
int arr[301][301];
int solve(int a,int b,int c,int d) {
	int sum = 0;
	for (int i = a; i <= c; i++) {
		for (int j = b; j <= d; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << solve(a, b, c, d) << "\n";		
	}
}

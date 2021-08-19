#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<memory.h>
using namespace std;
int n;
void solve(int n, int from, int to, int by) {
	if (n == 1)cout << from << ' ' << to << '\n';
	else {
		solve(n - 1, from, by, to);
		cout << from << ' ' << to << '\n';
		solve(n - 1, by, to, from);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cout << (1 << n) - 1 << '\n'; // 하노이탑에서 2^n-1이 최소 횟수
	solve(n, 1, 3, 2);
}

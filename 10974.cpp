#include <iostream>
#include <algorithm>
using namespace std;
int n;
bool visit[9];
int arr[9];
void solve(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = i;
			solve(cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	solve(0);
}

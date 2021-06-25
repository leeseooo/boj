#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int arr[8];
bool visit[8];
void search(int cnt, int idx) {
	if (cnt == m) {
		for (int j = 0; j < m; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i <= n; i++) {
		arr[cnt] = i;
		search(cnt + 1, i);
	}
}
int main() {
	cin >> n >> m;
	search(0, 1);
}

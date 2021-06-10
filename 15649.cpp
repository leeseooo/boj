#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string>
using namespace std;
int n, m;
int arr[9];
bool visit[9];
void func(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = i;
			func(cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	func(0);
}

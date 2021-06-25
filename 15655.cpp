#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int arr[9];
int input[9];
bool visit[9];
void search(int cnt, int idx) {
	if (cnt == m) {
		for (int j = 0; j < m; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i <= n; i++) {// 중복되지 않게 하기 위해 idx 변수 이용
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = input[i];
			search(cnt + 1, i+1);
			visit[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	sort(input, input + n + 1);
	search(0, 1);
}

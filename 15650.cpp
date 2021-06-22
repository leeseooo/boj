#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
int n, m;
int arr[9];
bool visit[9];
void search(int cnt,int idx) {//idx 추가 -> 증가하면서 이전의 작은 수는 고려x
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = i;
			search(cnt + 1,i+1);
			visit[i] = false;
			
		}
	}
}
int main() {
	cin >> n >> m;
	search(0,1);
}

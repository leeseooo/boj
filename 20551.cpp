#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <map>
#include <memory.h> 
using namespace std;
int n, m;
int arr[200001];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		int idx = lower_bound(arr, arr + n, num) - arr;
		if (idx != n && arr[idx] == num) {
			cout << idx << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
}

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 1000001
int t, n, m;
int note1[MAX];
int note2[MAX];
int search(int key) {
	int start = 0, end = n - 1;
	while (start <= end) {
		long long mid = (start + end) / 2;
		if (note1[mid] == key) return 1;
		else if (note1[mid] > key) end = mid - 1;
		else if (note1[mid] < key) start = mid + 1;
	}
	return 0;
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> note1[i];
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> note2[i];
		}
		sort(note1, note1 + n);
		for (int i = 0; i < m; i++) {
			int ans = search(note2[i]);
			cout << ans << "\n";
		}
	}
}

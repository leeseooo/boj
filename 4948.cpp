#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[1000001];
int main() {
	while (1) {
		cin >> n;
		int cnt = 0;
		if (n == 0)break;
		arr[1] = 1;
		for (int i = 2; i <= 2 * n; i++) {
			for (int j = i * 2; j <= 2 * n; j += i) {
				if (arr[j] != 1) arr[j] = 1;
			}
		}
		for (int i = n+1; i <= 2 * n; i++) {
			if (arr[i] == 0) cnt++;
		}
		cout << cnt << "\n";
	}
}

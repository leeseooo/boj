#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	int arr[1001] = { 0, };
	cin >> a >> b;
	int tmp = 1;
	int num = 1;
	for (int i = 1; i <= 1000; i++) {
		if (tmp == num) {
			tmp = 1;
			arr[i] = num++;
		}
		else {
			arr[i] = num;
			tmp++;
		}
	}
	int sum = 0;
	for (int i = a; i <= b; i++) {
		sum += arr[i];
	}
	cout << sum;
}

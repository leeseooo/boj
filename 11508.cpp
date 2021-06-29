#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n;
int cost[100001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	sort(cost, cost + n, greater<>());
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (i % 3 != 2) {
			sum += cost[i]; //비싼것부터 묶어야 젤 쌈
		}
	}
	cout << sum;
}

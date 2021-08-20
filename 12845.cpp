#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<memory.h>
using namespace std;
int n;
long long card[1001];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card, card + n, cmp);
	long long sum = 0;
	long long level = card[0];
	for (int i = 1; i < n ; i++) {
		sum += level + card[i];
	}
	cout << sum;
}

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <memory.h>
#include <queue>
using namespace std;
#define m 1234567891
int n;
string s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	long long sum = 0;
	long long r = 1;
	for (int i = 0; i < n; i++) {
		sum += ((s[i] - 'a' + 1)*r) % m;
		r = (r * 31) % m;
	}
	cout << sum % m;
}

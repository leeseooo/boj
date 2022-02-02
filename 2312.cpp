#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <map>
#include <memory.h> 
using namespace std;
int tc;
bool arr[100001];
void prime() {
	memset(arr, true, sizeof(arr));
	arr[1] = false;
	for (int i = 2; i*i < 100001; i++) {
		if (!arr[i])continue;
		for (int j = i * i; j < 100001; j += i) {
			arr[j] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> tc;
	prime();
	while (tc--) {
		int n;
		cin >> n;
		map<int, int>m;
		for (int i = 2; i <= n; i++) {
			if (!arr[i])continue;
			
			if (n % i == 0) {
				while (!(n % i)) {//나누어질때까지
					m[i]++;
					n /= i;
				}
			}
		}
		for (auto i : m) {
			cout << i.first << ' ' << i.second << '\n';
		}
	}
}

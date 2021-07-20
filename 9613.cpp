#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
int t, n;
int gcd(int a,int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int arr[101] = { 0, };
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		vector<int>v;
		int tmp;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				tmp = gcd(arr[i],arr[j]);
				v.push_back(tmp);
			}
		}
		long long sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}
		cout << sum << "\n";
	}
}

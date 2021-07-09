#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, num, cnt=1;
string str;
int main() {
	while (1) {
		cin >> n;
		if (n == 0) break;
		string name[100];
		vector<pair<int, int>>v;
		cin.ignore();
		for (int i = 1; i <= n; i++) {
			getline(cin, name[i]);
			v.push_back({ i, 0 });
		}
		for (int i = 0; i < 2 * n - 1; i++) {
			cin >> num >> str;
			v[num-1].second++;
		}
		for (int i = 1; i <= n; i++) {
			if (v[i-1].second != 2) cout << cnt++ << " " << name[i] << "\n";
		}
	}
}

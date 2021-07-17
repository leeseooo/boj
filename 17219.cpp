#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
int n, k;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	map<string, string>m;
	string id, pw;
	while (n--) {
		cin >> id >> pw;
		m[id] = pw;
	}
	string search;
	while (k--) {
		cin >> search;
		cout << m[search] << "\n";
	}
}

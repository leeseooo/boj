#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	string str[10001];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	string s;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (str[j].find(s) != string::npos) {
				int idx = str[j].find(s);
				if (idx == 0) {
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt;
}

#include <iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int t, n;
int main() {
	cin >> t;
	while (t--) {
		map<string, int>m;
		cin >> n;
		string key, value;
		for (int i = 0; i < n; i++) {
			cin >> value >> key;
			if (m.find(key) == m.end()) {
				m.insert({ key,1 });
			}
			else m[key]++;
		}
		int ans = 1;
		for (auto i = m.begin(); i != m.end(); i++) {
			ans *= i->second + 1; //(2+1)*(1+1)-1=5
		}
		cout << ans - 1 << "\n";
	}
}

/*
key를 찾은 경우: element의 iterator
key를 못 찾은 경우 : map::end
*/

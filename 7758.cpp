#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
int n;
int main() {
	cin >> n;
	string name, log;
	map<string, string,greater<>>m;
	while (n--) {
		cin >> name >> log;
		m[name] = log;
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->second == "enter") {
			cout << i->first << "\n";
		}
	}
}

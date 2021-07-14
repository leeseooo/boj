#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int n;
map<string, int>m;
int main() {
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[s]++;
	}
	int cnt = 0;
	for (auto i = m.begin(); i != m.end(); i++) {
		cnt = max(cnt, i->second); //i->second는 map의 value값
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		if (cnt == i->second) {
			cout << i->first;
      break;
		}
	}
}

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
int n;
vector<string>v;
void check(string s) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < s.length(); j++) {
			if (v[i] == s) return;
			s += s.at(0);
			s.erase(0, 1);
		}
	}
	v.push_back(s);
}
int main() {
	cin >> n;
	while (n--) {
		string tmp;
		cin >> tmp;
		if (v.empty()) v.push_back(tmp);
		else check(tmp);
	}
	cout << v.size();
}

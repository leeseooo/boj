#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
vector<int>v;
int arr[5] = { 1,2,3,4,5 };
bool check() {
	for (int i = 0; i < v.size(); i++) {
		if (arr[i] != v[i]) {
			return false;
		}
	}
	return true;
}
void print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	while (1) {
		if (check()) break;
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] > v[i + 1]) {
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
				print();
			}
		}
	}
}

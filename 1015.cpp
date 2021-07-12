#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back({ a,i });
	}
	sort(v.begin(), v.end());
	//2 0 1
	vector<pair<int,int>>vec;
	for (int i = 0; i < n; i++) {
		vec.push_back({ v[i].second,i });
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		cout << vec[i].second << " ";
	}
}

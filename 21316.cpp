#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[13];
vector<int>v[13];
vector<int>three;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	for (int i = 0; i < 12; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= 12; i++) {
		if (v[i].size() == 3)three.push_back(i);// 3 4 7 9
	}
	for (int i = 0; i < three.size(); i++) {
		int sum = 0;
		int node = three[i];
		for (int j = 0; j < v[node].size(); j++) {
			int next = v[node][j];
			sum += v[next].size();
		}
		if (sum == 6) {
			cout << node;
			return 0;
		}
	}
}

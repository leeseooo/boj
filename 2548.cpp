#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int arr[20001];
vector<pair<int, int>>ans;
int main() {
	int _max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		_max = max(_max, arr[i]);
	}
	int num = 1;
	while (1) {
		int term = 0;
		if (num > _max)break;
		for (int i = 0; i < n; i++) {
			term += abs(arr[i] - num);
		}
		ans.push_back({ term,num });
		num++;
	}
	sort(ans.begin(), ans.end());
	cout << ans[0].second;
}

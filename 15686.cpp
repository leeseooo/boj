#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
int n, m;
int arr[51][51];
vector<pair<int, int>>v;
bool check[51] = { false, };
vector<pair<int, int>>tmp;
vector<pair<int, int>>house;
int ans = 987654321;
int getDist(vector<pair<int,int>>tmp, pair<int,int>h) {
	int d = 987654321;

	for (int j = 0; j < tmp.size(); j++) {
		d = min(d, abs(h.first - tmp[j].first) + abs(h.second - tmp[j].second));
	}

	return d;
}

void recur(int cnt, int idx) {
	if (cnt == m) {
		int dist = 0;
		for (int i = 0; i < house.size(); i++) {
			dist += getDist(tmp, house[i]);
		}
		if (ans > dist) {
			ans = dist;
		}
		return;
	}
	for (int i = idx; i < v.size(); i++) { //조합
		if (!check[i]) {
			check[i] = true;
			tmp.push_back({ v[i].first,v[i].second });
			recur(cnt + 1, i);
			check[i] = false;
			tmp.pop_back();
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (arr[i][j] == 2) {
				v.push_back({ i,j }); //치킨집 좌표 저장
			}
		}
	}
	recur(0, 0);
	cout << ans;
}

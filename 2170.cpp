#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
#include<math.h>
using namespace std;
#define INF 1000000000
int n;
int x, y;
vector<pair<int, int>>v;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	int start = -INF;
	int end = -INF;
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		int tmp = v[i].first;
		int next = v[i].second;
		if (tmp <= end) {//겹치면 길이 연장
			end = max(end, next);
			//sum = end - start;
		}
		else if (tmp > end) {//겹치지 않으면 기존 길이 더하고 위치갱신
			sum += end - start;
			start = tmp;
			end = next;
		}
	}
	sum += end - start;
	//계속 겹쳤다면 마지막에 길이갱신, 마지막에 겹치지 않았다면 바뀐위치로 길이갱신
	cout << sum;
}

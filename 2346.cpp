#include<iostream>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
int main() {
	int n;
	deque<pair<int, int>>dq;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		dq.push_back({ i,a });
	}
	int pos = 0, target;
	pair<int, int>p;
	p = dq.front();
	dq.pop_front();
	cout << p.first;
	target = p.second;
	while (!dq.empty()) {
		pos = 0;
		if (target > 0) {
			while (++pos < target) {
				p = dq.front();
				dq.pop_front();
				dq.push_back(p);
			}
			p = dq.front(); dq.pop_front();
		}
		else {
			while (pos-- > target) {//음수면 뒤로 돌아야함
				p = dq.back();
				dq.pop_back();
				dq.push_front(p);
			}
			p = dq.front(); dq.pop_front();
		}
		target = p.second;
		cout << " " << p.first;
	}
}

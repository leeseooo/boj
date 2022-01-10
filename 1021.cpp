#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int n, m;
deque<int>dq;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num; //뽑으려는 수
		int idx = 0; //뽑으려는 수의 인덱스
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) {
				idx = i;
				break;
			}
		}
		if (idx < dq.size() - idx) {
			while (dq.front() != num) {
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			dq.pop_front();
		}
		else {
			while (dq.front() != num) {
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
			dq.pop_front();
		}
	}
	cout << cnt;
}

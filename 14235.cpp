#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
int n;
priority_queue<int>pq;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a != 0) {
			for (int j = 0; j < a; j++) {
				int val;
				cin >> val;
				pq.push(val);
			}
		}
		else {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
	}
}

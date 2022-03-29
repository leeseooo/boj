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
	int first;
	cin >> first;
	int num;
	for (int i = 0; i < n - 1; i++) {
		cin >> num;
		pq.push(num);
	}
	int cnt = 0;
	while (!pq.empty() || pq.size() > 1) {
		if (pq.top() < first)break;
		first++;
		cnt++;
		int top = pq.top();
		pq.pop();
		pq.push(top - 1);
	}
	cout << cnt;
}

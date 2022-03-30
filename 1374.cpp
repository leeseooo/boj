#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
using pii = pair<int, int>;
int n;
priority_queue<pii, vector<pii>, greater<pii>>pq;
priority_queue<int, vector<int>, greater<>>room;//종료시간 빠른 순으로 나오는 큐
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ b,c });
	}
	room.push(pq.top().second);
	pq.pop();

	while (!pq.empty()) {
		//젤 빨리끝나는 강의 다음으로 시작하는 강의는 기존강의실에 배정
		if (room.top() <= pq.top().first) {
			//종료시간 큐 갱신
			room.push(pq.top().second);
			room.pop();
		}
		else {
			room.push(pq.top().second);
		}
		pq.pop();
	}
	cout << room.size();
}

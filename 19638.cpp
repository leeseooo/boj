#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int n, centi, t;
	priority_queue<int>pq;
	int h;
	cin >> n >> centi >> t;
	for (int i = 0; i < n; i++) {
		cin >> h;
		pq.push(h);
	}
	for (int i = 0; i < t; i++) {
		int bigman = pq.top();
		if (bigman < centi) { //pq.top이 centi보다 작으면 나머지 거인들도 다 작은것
			cout << "YES\n" << i << "\n";
			return 0;
		}
		else if (bigman > 1) {
			pq.pop();
			pq.push(bigman / 2);//큰 거인부터 때릴거라서 큐에 계속 다시 넣어줌
		}
	}
	if (pq.top() < centi) {
		cout << "YES\n" << t << "\n";
	}
	else
		cout << "NO\n" << pq.top() << "\n";
}

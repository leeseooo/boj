#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
int main() {
	int n;
	cin >> n;
	int s;
	priority_queue<int>pq;
	for (int i = 0; i < n; i++) {
		cin >> s;
		pq.push(s);
	}
	int score = 0;
	while (1) {
		if (pq.size() == 1)break;
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		pq.push(x + y);
		score += x * y;
	}
	cout << score;
}

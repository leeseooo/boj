#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int> > pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			pq.push(num);
		}
		for (int k = 0; k < n; k++) {
			pq.pop();
		}
	}
	cout << pq.top();
}

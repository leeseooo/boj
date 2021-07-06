#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int m, x, y;
int ball = 1;
int main() {
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (ball == x) ball = y;
		else if (ball == y) ball = x;
	}
	cout << ball;
}

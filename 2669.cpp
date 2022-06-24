#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int answer = 0;
	int arr[101][101] = { 0, };
	for (int i = 0; i < 4; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = a; j < c; j++) {
			for (int k = b; k < d; k++) {
				arr[j][k]++;
			}
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] != 0)answer++;
		}
	}
	cout << answer << '\n';
}

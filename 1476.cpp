#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <map>
#include <memory.h> 
using namespace std;
int a, b, c;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> b >> c;
	int day = 1;
	int year[3] = {1,1,1};
	while (1) {
		bool flag[3] = { false, };
		if (year[0] == a && year[1] == b && year[2] == c) {
			cout << day;
			return 0;
		}
		if (year[0] % 15 == 0) {
			year[0] = 1; flag[0] = true;
		}
		if (year[1] % 28 == 0) {
			year[1] = 1; flag[1] = true;
		}
		if (year[2] % 19 == 0) {
			year[2] = 1; flag[2] = true;
		}
		for (int i = 0; i < 3; i++) {
			if (!flag[i]) {
				year[i]++;
			}
		}
		day++;
	}
}

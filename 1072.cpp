#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long x, y;
	cin >> x >> y;
	int z = (y * 100) / x;
	if (z >= 99) {//99% -> 100%는 절대 안됨
		cout << -1;
		return 0;
	}
	long long low = 0; long long high = INF;
	while (low <= high) {
		long long mid = (low + high) / 2;
		int tmp = ((y + mid) * 100) / (x + mid);
		if (tmp > z) {
			high = mid - 1;
		}
		else if(tmp == z){
			low = mid + 1;
		}
	}
	cout << low;
}

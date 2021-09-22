#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
int t, h, w, n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;
		int col, row;
		if (n % h != 0) {
			col = n % h;
			row = n / h + 1;
		}
		else {
			col = h;
			row = n / h;
		}
		if (row < 10) {
			cout << col << '0' << row << '\n';
		}
		else {
			cout << col << row << '\n';
		}
	}
}

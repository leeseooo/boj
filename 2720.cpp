#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory.h>
#include<queue>
using namespace std;
int main() {
	int t;
	int res;
	cin >> t;
	while (t--) {
		cin >> res;
		int quarter = res / 25;
		int dime = (res % 25) / 10;
		int nickel = ((res % 25) % 10) / 5;
		int penny = ((res % 25) % 10) % 5;

		cout << quarter << " " << dime << " " << nickel << " " << penny << "\n";
	}
}

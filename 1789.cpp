#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long s;
	cin >> s;
	int num = 1;
	int n = 0;
	long long sum = 0;
	while (1) {
		if (sum > s) {
			n--;
			break;
		}
		sum += num++;
		n++;
	}
	cout << n;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;
int x;
int cnt = 0;
int main() {
	cin >> x;
	if (x < 100) {
		cout << x;
		return 0;
	}
	else if(x>=100 && x<1000){
		cnt += 99;
		for (int i = 111; i <= x; i++) {
			int a = i / 100;
			int b = i % 100 / 10;
			int c = i % 100 % 10;
			if (abs(a - b) == abs(b - c)) {
				if((a-b <= 0 && b-c <= 0) || (a-b)>0 && (b-c)>0)
					cnt++;
			}
		}
		cout << cnt;
	}
	else if (x == 1000) {
		cout << "144";
	}
}

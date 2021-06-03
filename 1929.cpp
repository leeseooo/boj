//에라토스테네스의 체 이용

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
bool prime[1000001];
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 2; i < 1000000; i++) {
		prime[i] = true;
	}
	prime[1] = false;
  
  //에라토스테네스의 체
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == true) {//아직 안 지워진 수라면
			for (int j = 2 * i; j <= 1000000; j += i) { //소수의 배수를 제거
				prime[j] = false;
			}
		}
	}
	for (int j = m; j <= n; j++) {
		if (prime[j]) {
			printf("%d\n", j);
		}
	}
}

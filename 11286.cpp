#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>
using namespace std;
priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>>pq;
//절댓값과 원래값 동시에 저장, greater를 통해 작은수부터
int n, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x) {
			pq.push({ abs(x),x });
		}
		else { //x가 0일때
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top().second);
				pq.pop();
			}
		}
	}
}

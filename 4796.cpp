#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
#include<memory.h>
using namespace std;
int main() {
	int P, L, V;
	int idx = 1;
	while (1) {
		cin >> L >> P >> V;
		if (!L && !P && !V) {
			break;
		}
		int ans = 0;
		ans += (V / P)*L;
		ans += V % P < L ? V % P : L;
		//V%P가 L이하인 경우 나머지 더해주고
		//V%P가 L보다 클 경우 L을 더해줌 ex) 5 8 30 => V%P를 더해버리면 21이 나옴.
		printf("Case %d: %d\n", idx++, ans);
	}
}

//테스트케이스를 제발 여러개 돌려보고 답을 내도록 하자

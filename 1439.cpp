#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory.h>
#include<queue>
using namespace std;
int main() {
	string s;
	int one = 0, zero = 0;
	cin >> s;

	int flag = -1; //연속되는지 체크
	for (int i = 0; i < s.size(); i++) {
		if (flag != 0 && s[i] == '0') {// 연속 0 더미 개수계산
			zero++;
			flag = 0;
		}
		else if (flag != 1 && s[i] == '1') {// 연속 1 더미 개수계산
			one++;
			flag = 1;
		}
	}
	cout << min(zero, one);// 더 적은 더미만 뒤집어준다.
}

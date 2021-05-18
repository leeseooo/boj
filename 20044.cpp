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
	int n;
	vector<int>v;

	cin >> n;

	for (int i = 0; i < n * 2; i++) {
		int w;
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end());//오름차순 정렬

	int ans = 200001;//팀 코딩역량 최댓값
	for (int i = 0; i < n; i++) {
		//가장작은값+가장큰값, 두번째로작은값+두번째로큰값,... 
		//팀원의 코딩 역량의 합을 최대한 일정하게 유지하기 위함
		ans = min(ans, v[i] + v[2 * n - 1 - i]);
	}
	cout << ans;
}

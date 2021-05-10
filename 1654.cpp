#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, k;
vector<int>v;
int ans = 0;
int binarySearch() {
	//mid값을 구할때 랜선끼리의 덧셈과정에서 int범위 넘을수도 있어서 long long
	long long low = 1, high = v.front(); //low =0하면 부동소수에러남
	while (low <= high) {
		int cnt = 0;
		long long mid = (low + high) / 2;
		for (int i = 0; i < k; i++) {
			cnt += v[i] / mid;
		}
		if (cnt < n) {
			high = mid - 1;
		}
		else if (cnt >= n) {
			low = mid + 1;
			ans = mid;
		}
	}
	return ans;
}
int main() {
	scanf("%d %d", &k, &n);
	int line;
	for (int i = 0; i < k; i++) {
		scanf("%d", &line);
		v.push_back(line);
	}
	sort(v.begin(), v.end(),greater<int>());
	
	printf("%d", binarySearch());
}

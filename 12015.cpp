#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	vector<int>v;
	cin >> n;
	v.push_back(0); //초기값 하나 넣어놓음

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > v.back()) {//마지막값보다 크다면
			v.push_back(num);
		}
		else {//작다면
			int idx = lower_bound(v.begin(), v.end(), num)-v.begin();
			v[idx] = num;
		}
	}
	cout << v.size() - 1;
}
//lower_bound는 key값보다 크거나 같은 가장 작은 정수 값을 탐색
//arr[mid-1] < key 이면서 arr[mid] >= key 인 최소의 m 값

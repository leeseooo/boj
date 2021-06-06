#include<iostream>
#include<algorithm>
using namespace std;
int k;
int arr[13];
int lotto[6];
void func(int start,int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << "\n";
		return; //리턴 시 아래 반복문 재귀호출로 돌아가서 다시 처리
	}
	for (int i = start; i < k; i++) {
		lotto[depth] = arr[i];
		func(i + 1, depth + 1);
	}
}
int main() {
	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		func(0, 0);
		cout << "\n";
	}
}

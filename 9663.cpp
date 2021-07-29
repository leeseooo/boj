#include<iostream>
using namespace std;
int n;
int arr[15];//퀸 특성상 체스판 한 행 당 한개의 퀸만 존재 가능하므로 1차원 배열로 만든다.
int res = 0;
bool check(int row) {
	for (int j = 0; j < row; j++) {
		if (arr[j] == arr[row] || abs(arr[row] - arr[j]) == row - j) {//같은 열이거나 대각선에 위치하는 경우
			return false;
		}
	}
	return true;
}
void n_queen(int row) {//i는 현재 몇번째 행이 퀸 배치중인지 기록하는 변수
	if (row == n) {//퀸을 배치한 총 횟수가 n이 되면 모든 행에 배치한 것.
		res += 1;
	}
	else {
		for (int j = 0; j < n; j++) {
			arr[row] = j;//해당 행에 퀸 배치
			if (check(row)) {//true이면 다음 퀸, false이면 j를 통해 위치변경
				n_queen(row + 1);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	n_queen(0);
	cout << res;
}

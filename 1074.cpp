#include<iostream>
#include<algorithm>
using namespace std;
int N, r, c;
int ans;
int dx[4] = { 0,0,1,1 };
int dy[4] = { 0,1,0,1 }; //Z모양으로
void solve(int x,int y, int size) {//size는 한 변의 길이
	if (x == r && y == c) {
		cout << ans;
		exit(0);
	}
	//현재 영역에서 해당 좌표 포함하고 있다면 다시 4조각을 분할하고 탐색
	if (r <= x + size - 1 && c <= y + size - 1);
	//포함하지 않는다면 이 영역에 그 좌표가 없다는 뜻 => 네모 size만큼 건너뛰기
	else {
		ans += size * size;
		return;
	}

	solve(x, y, size / 2); //left top
	solve(x, y + size / 2, size / 2);//right top
	solve(x + size / 2, y, size / 2);//left bottom
	solve(x + size / 2, y + size / 2, size / 2);//right bottom
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> r >> c;
	solve(0, 0, 1 << N);
}

/*
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int N, r, c;
int ans;
int dx[4] = { 0,0,1,1 };
int dy[4] = { 0,1,0,1 }; //Z모양으로
void solve(int x,int y, int size) {//size는 한 변의 길이
	if (size == 2) {// 2*2 일때 하나의 Z가 나올 수 있다
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx == r && ny == c) {
				cout << ans;
				exit(0);
			}
			ans++;
		}
		return;
	}
	solve(x, y, size / 2); //left top
	solve(x, y + size / 2, size / 2);//right top
	solve(x + size / 2, y, size / 2);//left bottom
	solve(x + size / 2, y + size / 2, size / 2);//right bottom
}
void answer() {
	solve(0, 0, 1 << N);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> r >> c;
	answer();
}
*/

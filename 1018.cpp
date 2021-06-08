#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
}; //미리 체스판을 선언해놓고 고칠 부분을 비교한다. 이때 B로 시작하는 체스판, W로 시작하는 체스판 둘다 비교해서 최소수정개수를 찾아야함
string board[50];
int n, m;
int WB_cnt(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != WB[i][j]) cnt++; //한줄 한줄씩 비교(이때 보드판의 시작좌표에 i와 j를 더해 좌표 움직여야함)
        }
    }
    return cnt;
}
int BW_cnt(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != BW[i][j]) cnt++;
        }
    }
    return cnt;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int min_val = 5000;
    for (int i = 0; i+8 <= n; i++) { //현재 인덱스+8이 범위를 초과하지 않게끔
        for (int j = 0; j+8 <= m; j++) {
            int tmp = min(WB_cnt(i, j), BW_cnt(i, j));// 8x8 구역 최소개수
            min_val = min(min_val, tmp); //최소개수들 중 가장 최소값
        }
    }
    cout << min_val;
}

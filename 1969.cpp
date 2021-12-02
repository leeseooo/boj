#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
string str[1001];
int dna[1001][4];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			switch (str[i][j]) {
			case 'A':dna[j][0]++; break;
			case 'C':dna[j][1]++; break;
			case 'G':dna[j][2]++; break;
			case 'T':dna[j][3]++; break;
			}
		}
	}
	int dist = 0;
	string ans = "";
	for (int i = 0; i < m; i++) {
		int idx = 0; //어떤 알파벳이 가장 많이 쓰였는지 idx체크
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (dna[i][j] > cnt) {
				cnt = dna[i][j];//가장 많이 쓰인 알파벳 개수
				idx = j;
			}
		}
		dist += n - cnt;//나머지는 해당 알파벳이 아니라는 뜻이므로 n에서 빼줌
		switch (idx) {
		case 0:ans += 'A'; break;
		case 1:ans += 'C'; break;
		case 2:ans += 'G'; break;
		case 3:ans += 'T'; break;
		}
	}
	cout << ans << '\n' << dist;
}

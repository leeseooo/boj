#include <iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<memory.h>
using namespace std;
int n;
bool visit[201][201] = { false };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		string a, b, c;
		cin >> a >> b >> c;
		if (a.size() + b.size() != c.size()) {
			cout << "Data set " << i << ": no\n";
			continue;
		}
		visit[0][0] = true;
		queue<pair<int, int>>q;
		q.push({ 0,0 });
		bool flag = false;
		while (!q.empty()) {
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			int k = i + j;// string c를 참조할 인덱스

			if (i == a.size() && j == b.size() && k == c.size()) {
				//끝까지 갔다면
				flag = true;
				break;
			}
			if (i != a.size() && a[i] == c[k] && !visit[i + 1][j]) {
				//현재 a 인덱스+1의 문자를 참조하지 않았다면
				visit[i + 1][j] = true;
				q.push({ i + 1,j }); //다음 문자로 가준다.
			}
			if (j != b.size() && b[j] == c[k] && !visit[i][j + 1]) {
				visit[i][j + 1] = true;
				q.push({ i,j + 1 });
			}
		}
		if (!flag) {
			cout << "Data set " << i << ": no\n";
		}
		else {
			cout << "Data set " << i << ": yes\n";
		}
	}
}

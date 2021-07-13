#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int arr[501][501];
bool visit[501];
bool myFriend[501];
int cnt = 0;
void search() {
	for (int i = 2; i <= n; i++) { //상근이의 친구
		if (arr[1][i] == 1) {
			visit[i] = true;
			myFriend[i] = true;
		}
	}
	for (int i = 2; i <= n; i++) { //상근이의 친구의 친구
		if (myFriend[i]) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j]) {
					visit[j] = true;
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (visit[i]) cnt++;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	search();
	cout << cnt;
}
/* 틀렸던 코드 
친구의 번호보다 친구 여부가 더 중요하기 때문에 굳이 v[a].push_back(b) 이런식으로 하지말고
0또는1로 친구여부를 체크해주고 bool type의 배열을 이용해서 구현할 수 있다.
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
vector<int>v[501];
bool visit[501];
int cnt = 0;

void dfs(int node) {
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!visit[next]) {
			cnt++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a); //서로 친구이다.
	}
	cnt += v[1].size();
	visit[1] = true;
	for (int i = 0; i < v[1].size(); i++) {
		visit[v[1][i]] = true;
	}
	for (int i = 0; i < v[1].size();i++) {
		dfs(v[1][i]);
	}
	cout << cnt;
}
*/

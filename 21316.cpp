#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[13];
vector<int>v[13];
vector<int>three;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	for (int i = 0; i < 12; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);//양방향으로 저장
	}
	//정점과 연결된 간선의 갯수는 1,2,3개 중 하나이다.
	for (int i = 1; i <= 12; i++) {
		if (v[i].size() == 3)three.push_back(i);//3개인 것만 저장 (3,4,7,9)
	}
	//간선갯수 3개인 별들과 연결된 정점의 간선의 합이 6인 별이 스피카
	for (int i = 0; i < three.size(); i++) {
		int sum = 0;
		int node = three[i];
		for (int j = 0; j < v[node].size(); j++) {
			int next = v[node][j];
			sum += v[next].size();
		}
		if (sum == 6) {
			cout << node;
			return 0;
		}
	}
}

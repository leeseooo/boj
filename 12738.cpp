#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v.push_back(-1000000001); //초기값을 넣어놓는다
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > v.back()) {//연속해서 증가하고 있다면 insert
			v.push_back(num);
		}
		else {
			//해당 num과 같거나 큰 index 찾아서 갱신
			int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
			v[idx] = num;
		}
	}
	v.erase(v.begin(), v.begin()+1); //지우고 출력하거나 v.size()-1
	cout << v.size();
}

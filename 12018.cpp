#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int>lec;
	for (int i = 0; i < n; i++) {
		int p, l;
		cin >> p >> l;
		vector<int>v(p);
		for (int j = 0; j < p; j++) {
			cin >> v[j];
		}
		if (p < l) {
			lec.push_back(1);
			continue;
		}
		sort(v.begin(), v.end(), greater<>());
		lec.push_back(v[l - 1]);//큰것부터 L번째 순서의 마일리지를 넣어줌
		//틀린생각 : 오름차순 정렬하고 앞에서 2번째꺼 넣어주려고 한 것->p에 따라 다르므로 틀림
	}
	sort(lec.begin(), lec.end());
	int ans = 0;
	for (int i = 0; i < lec.size(); i++) {
		if (m >= lec[i]) {
			m -= lec[i];
			ans++;
		}
		else break;
	}
	cout << ans;
}

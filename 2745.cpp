#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<memory.h>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string N;
	int B;
	cin >> N >> B;
	int tmp=0;
	int cnt = 0;
	for (int i = N.size() - 1; i >= 0; i--) {
		if (N[i] >= 'A' && N[i] <= 'Z') {
			tmp += (N[i] - 'A' + 10)*(pow(B, cnt));
		}
		else {
			tmp += (N[i] - '0')*(pow(B, cnt));
		}
		cnt++;
	}
	cout << tmp;
}

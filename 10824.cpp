#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include <map>
#include <memory.h> 
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string ab = to_string(a) + to_string(b);
	string cd = to_string(c) + to_string(d);
  
	//문자열을 숫자형으로 변형
	long long first = stoll(ab);
	long long second = stoll(cd);
	cout << first + second;
}

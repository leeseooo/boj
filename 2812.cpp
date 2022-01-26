#include <iostream>
#include<deque>
#include<string>
using namespace std;
int n,k;
deque<char>dq;
string str;
int main() {
	cin >> n >> k >> str;
	for(int i=0;i<str.length();i++){
		while(!dq.empty() && k != 0 && dq.back() < str[i]){
			//추가할 숫자가 이전 숫자보다 작을때까지 pop
			dq.pop_back();
			k--;
		}
		dq.push_back(str[i]);
	}
	/*반례
	2 1
	21 
	*/
	for(int i=0;i<dq.size()-k;i++){//k가 깎이지 않았을경우(작은 숫자들이 push_back되므로 k만큼 빼줘야됨)
		cout << dq[i];
	}
}

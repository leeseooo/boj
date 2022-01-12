#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int t;
int main() {
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		stack<char>left,right;
		
		for(int i=0;i<str.size();i++){
			if(str[i] == '<'){
				if(left.empty())continue;
				right.push(left.top());
				left.pop();
			}
			else if(str[i] == '>'){
				if(right.empty())continue;
				left.push(right.top());
				right.pop();
			}
			else if(str[i] == '-'){
				if(left.empty())continue;
				left.pop();
			}
			else{
				left.push(str[i]);
			}
		}
		while(!left.empty()){
			right.push(left.top());
			left.pop();
		}
		while(!right.empty()){
			cout << right.top();
			right.pop();
		}
		cout << '\n';
	}
	return 0;
}

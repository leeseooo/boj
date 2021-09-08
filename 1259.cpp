#include <iostream>
#include<string>
using namespace std;
string s;
int main() {
	while(1){
		cin >> s;
		if(s == "0")break;
		string tmp;
		if(s.length()%2==0){
			int idx = s.length()/2;
			for(int i=0;i<idx;i++){
				tmp += s[i];
			}
			bool flag = true;
			int j=0;
			for(int i=s.length()-1;i>=idx;i--){
				if(tmp[j++] != s[i]){
					flag = false;
					break;
					}
			}
			if(flag)cout << "yes\n";
			else cout << "no\n";
		}
		else{
			int idx = s.length()/2;
			for(int i=0;i<idx;i++){
				tmp += s[i];
			}
			bool flag = true;
			int j=0;
			for(int i=s.length()-1;i>idx;i--){
				if(tmp[j++] != s[i]){
					flag = false;
					break;
					}
			}
			if(flag)cout << "yes\n";
			else cout << "no\n";
		}
	}
	return 0;
}

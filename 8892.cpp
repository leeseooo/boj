#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int t,k;
int pelindrom(string s){
	int len = s.length();
	int low=0; int high=s.size()-1;
	while(low<high){
			if(s[low++] != s[high--]){
			return -1;
		}
	}
	return 1;
}
int main() {
	cin >> t;
	while(t--){
		cin >> k;
		string str[101];
		for(int i=0;i<k;i++){
			cin >> str[i];
		}
		bool flag=false;
		for(int i=0;i<k;i++){
			if(flag)break;
			string tmp = str[i];
			for(int j=0;j<k;j++){
				if(i == j)continue;
				string tmp_cp = tmp;
				tmp += str[j];
				int response = pelindrom(tmp);
				if(response == 1){
					cout << tmp << '\n';
					flag = true;
					break;
				}
				tmp = tmp_cp;
			}
		}
		if(!flag){
			cout << 0 << '\n';
		}
	}
}

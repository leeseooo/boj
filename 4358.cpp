#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
using namespace std;
int main() {
	map<string,float>tree;
	string str;
	int cnt=0;
	while(getline(cin,str)){
		cnt++;
		tree[str]++;
	}
	cout << fixed;
	cout.precision(4);
	for(auto i : tree){
		float per = (i.second / cnt) * 100;
		cout << i.first << ' ' << per << '\n';
	}
}

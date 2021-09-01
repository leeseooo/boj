#include <iostream>
#include<vector>
using namespace std;
unsigned long long n;
vector<unsigned long long>v;
void rec(unsigned long long a){
	if(a == 0)return;
	rec(a/2);
	v.push_back(a%2);
}
int main() {
	cin >> n;
	rec(n);
	for(unsigned long long i : v){
		cout << i;
	}
	return 0;
}

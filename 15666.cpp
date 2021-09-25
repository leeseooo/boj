#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[8];
int seq[8];
void solve(int cnt, int idx){
	if(cnt == m){
		for(int i=0;i<m;i++){
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}
	bool visit[10001]={false};
	for(int i=idx;i<n;i++){
		if(!visit[arr[i]]){
			visit[arr[i]] = true;
			seq[cnt] = arr[i];
			solve(cnt+1,i);
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	solve(0,0);
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int arr[500001];
int check[8001]={0,};
int main() {
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		check[arr[i]+4000]++;
	}
	sort(arr,arr+n);
	
	int sum=0;
	for(int i=0;i<n;i++){
		sum += arr[i];
	}
	double dsum = (double)sum / (double)n;
	cout << floor(dsum + 0.5) << '\n'; //floor()는 내림함수, 0.5를 더하면 반올림 구현 가능 
	
	int tmp[8001]={0,}; int idx=0; int maxCnt=0;
	for(int i=0;i<=8000;i++){
		if(check[i] != 0){
			maxCnt = max(maxCnt,check[i]);
		}
	}
	for(int i=0;i<=8000;i++){
		if(check[i] == maxCnt){
			tmp[idx++] = i;
		}
	}
	sort(tmp,tmp+idx);
	int ans = 0;
	if(idx > 1)ans = tmp[1]-4000;
	else ans = tmp[0]-4000;
	
	cout << arr[n/2] << '\n';
	cout << ans << '\n';
	cout << arr[n-1] - arr[0] << '\n';
	return 0;
}

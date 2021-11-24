#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;
int t,k;
bool visit[1000001];
int main() {
	cin >> t;
	while(t--){
		priority_queue<pair<int,int>>maxpq;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minpq;
		cin >> k;
		for(int i=0;i<k;i++){
			char op;
			int num;
			cin >> op >> num;
			if(op == 'I'){
				maxpq.push({num,i});
				minpq.push({num,i});//입력숫자, 인덱스 순서로 삽입
				//안그러면 우선순위 정렬 시 숫자정렬이 안됨
				visit[i] = true;
			}
			else{
				if(num == 1){//delete max num
					while(!maxpq.empty() && !visit[maxpq.top().second]){
						maxpq.pop();
					}
					if(!maxpq.empty()){
						visit[maxpq.top().second] = false;
						maxpq.pop();
					}
				}
				else{//delete min num
					while(!minpq.empty() && !visit[minpq.top().second]){
						minpq.pop();
					}
					if(!minpq.empty()){
						visit[minpq.top().second] = false;
						minpq.pop();
					}
				}
			}
		}
		while(!maxpq.empty() && !visit[maxpq.top().second]){
			maxpq.pop();
		}			
		while(!minpq.empty() && !visit[minpq.top().second]){
			minpq.pop();
		}
		if(maxpq.empty() && minpq.empty())cout << "EMPTY\n";
		else cout << maxpq.top().first << ' ' << minpq.top().first << '\n';
	}
	return 0;
}

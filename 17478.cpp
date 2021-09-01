#include <iostream>
using namespace std;
int n;
void f(int a){
	if(a == n){
		int tmp=0;
		while(tmp != 3){
			for(int i=0;i<4*a;i+=4){
			cout << "____";
		}
		if(tmp == 0)cout << "\"재귀함수가 뭔가요?\"\n";
		else if(tmp == 1) cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
		else if(tmp == 2)cout << "라고 답변하였지.\n";
		tmp++;
		}
		while(1){
			a--;
			for(int i=0;i<4*a;i+=4){
				cout << "____";
			}
			cout << "라고 답변하였지.\n";
			if(a == 0)exit(0);
		}
	}
	if(a != n){
		int cnt=0;
		while(cnt != 4){
			for(int i=0;i<4*a;i+=4){
			cout << "____";
			}
			if(cnt == 0)cout << "\"재귀함수가 뭔가요?\"\n";
		else if(cnt == 1)cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		else if(cnt == 2)cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		else if(cnt == 3)cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
		cnt++;
		}
	}
	f(a+1);
}
int main() {
	cin >> n;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	cout << "\"재귀함수가 뭔가요?\"\n";
	cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	f(1);
}

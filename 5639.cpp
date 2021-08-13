#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
int arr[1000001][2];
void postorder(int root) {
	if (root == -1)return;
	if (arr[root][0] != 0)postorder(arr[root][0]);
	if (arr[root][1] != 0)postorder(arr[root][1]);
	cout << root << "\n";
}
void preorder(int cur, int root) {
	if (cur > root) {//크면 오른쪽
		if (arr[root][1] == 0) {//우측자리 비어있으면 할당
			arr[root][1] = cur;
			return;
		}
		else {//채워져있으면 재귀
			preorder(cur, arr[root][1]);
		}
	}
	else if (cur < root) {//작으면 왼쪽
		if (arr[root][0] == 0) {
			arr[root][0] = cur;
			return;
		}
		else {
			preorder(cur, arr[root][0]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tmp;
	int root = -1;
	while (!cin.eof()) {
		cin >> tmp;
		if (root == -1)root = tmp;
		else preorder(tmp, root);
	}
	postorder(root);
}

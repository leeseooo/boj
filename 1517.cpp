#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[500001];
int tmp[500001];
long long swap_cnt = 0;
void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {//왼쪽이 오른쪽보다 작을때 => 순서변경 x
			tmp[k++] = arr[i++];
		}
		else {//오른쪽보다 왼쪽이 클때 => 오른쪽 수가 왼쪽으로 이동
			tmp[k++] = arr[j++];
			swap_cnt += mid - i + 1;//두 수의 거리를 카운트한다.
		}
	}
	//남아있는 값 복사
	while (i <= mid)tmp[k++] = arr[i++];
	while (j <= end)tmp[k++] = arr[j++];
	//임시배열 원본에 복사
	for (int i = start; i <= end; i++) {
		arr[i] = tmp[i];
	}
}
void merge_sort(int start, int end) {
	if (start == end)return;
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);
	merge(start, end);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_sort(0, n - 1);
	cout << swap_cnt;
}

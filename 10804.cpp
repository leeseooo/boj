#include<iostream>
#include<algorithm>
using namespace std;
int arr[21];
int s1, s2;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cin >> s1 >> s2;
		
		while (s1 <= s2) {
			swap(arr[s1], arr[s2]);
			s1++; s2--;
		}
	}
	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << " ";
	}
}

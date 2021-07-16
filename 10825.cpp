#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
struct st{
	string name;
	int language;
	int english;
	int math;
}p[100001];
bool cmp(st p1,st p2) {
	if (p1.language == p2.language && p1.english == p2.english && p1.math == p2.math) {
		return p1.name < p2.name;
	}
	if (p1.language == p2.language && p1.english == p2.english) {
		return p1.math > p2.math;
	}
	if (p1.language == p2.language) {
		return p1.english < p2.english;
	}
	return p1.language > p2.language;
}
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].name >> p[i].language >> p[i].english >> p[i].math;
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << p[i].name << "\n";
	}
}

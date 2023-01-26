#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>

#define x first
#define y second

using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
typedef long long LL;
typedef pair<int, int> PII;
vector<int> num;
LL pow10[10];
int s, n;
int cal() {
	int ans = 0;
	for(int i = 0; i < num.size(); ++i) {
		ans += num[i];
	}
	return ans;
}

void print() {
	int j = num.size() - 1;
	for(int i = 1; i < n; ++i) {
		while(!num[j]) j--;
		printf("%d ", pow10[j]);
		s -= pow10[j];
		--num[j];
	}
	printf("%d\n", s);
}

int main() {
	pow10[0] = 1;
	for(int i = 1; i < 10; ++i) pow10[i] = pow10[i - 1] * 10;
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &s, &n);
		int s1 = s;
		num.clear();
		while(s1) num.push_back(s1 % 10), s1 /= 10;
		while(cal() < n) {
			if(!num.back()) num.pop_back();
			int i = num.size() - 1;
			num[i]--;
			num[i - 1] += 10;
		}
//		cout << num.size() << endl;
//		cout << cal() << endl; 
		print();
	}
	
	return 0;
}


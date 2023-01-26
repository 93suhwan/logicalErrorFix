#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
#include<string>
//ll s[100005];
int a[300005];
int fa[300005];
#define inf 999999999
int cnt[300005];
int ans = 0;
int A[4];
int index = 0;
//int sum[6][100005];
//找一个最小的数k 使得n^k>m
int min(int x1, int x2) {
	if (x1 > x2)
		return x2;
	else
		return x1;
}
int max(int x1, int x2) {
	if (x1 < x2)
		return x2;
	else
		return x1;
}

int find(int x) {
	if (fa[x] != x) {
		return fa[x] = find(fa[x]);
	}
	else return fa[x];
}

void init(int n) {
	ans = n;
	memset(A, 0, sizeof(A));
	for(int i=1;i<=n;i++)
		fa[i] = i;
}

void in(int x, int y) {
	int xx = find(x);
	int yy = find(y);
	if (xx != yy) {
		--ans;
		fa[xx] = yy;
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;				
		index = 0;
		scanf("%d%d", &n, &m);
		//memset(a, 0, sizeof(a));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			cnt[(i - a[i]+ n) % n]++;
		}
		for (int k = 0; k <= n - 1; k++) {
			if (n - cnt[k] > m * 2)continue;
			init(n);
			for (int i = 1; i <= n; i++) {
				int aa = (i - k - 1+n) % n + 1;
				in(a[i], aa);
			}
			if (n - ans <= m) {
				A[++index] = k;
			}
		}
		cout << index << " ";
		for (int i = 1; i <= index; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
		
	}
}